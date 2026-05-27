#include "myserver.h"

MyServer::MyServer()
{
#ifdef DEBUG
    _log = spdlog::stdout_color_mt("BrainStorm");
#else
    _log = spdlog::rotating_logger_mt("Brainstorm","BrainStorm",1024*1024*5,3);
    _log->flush_on(spdlog::level::info);
#endif

    _db = new DB(NULL, "root", "123456", "BrainStorm");

    initRankMap();
}
void MyServer::connectEvent(TcpSocket *s)
{
    _log->info("有一个新连接[{}:{}]",s->getIp(),s->getPort());
}
void MyServer::readEvent(TcpSocket *s)
{
    char buf[1024] = {0};
    while(1)
    {
        int len = 0;
        s->readData(&len,sizeof(len));
        if(len <= 0)
        {
            break;
        }
        s->readData(buf,len);

        //数据解析
        Json::Value root;
        Json::Reader reader; //Json解析器
        if(!reader.parse(buf,root))
        {
            _log->error("json数据解析失败");
            return ;
        }
        int cmd = root["cmd"].asInt();
        switch(cmd)
        {
        case REGISTER:
            Register(s,root);
            break;
        case LOGIN:
            Login(s,root);
            break;
        case SINGLE_GETQUESTION:
            singleGetQuestion(s);
            break;
        case RANK:
            Rank(s);
            break;
        case ANSWER:
            rankAnswerOneQuestion(root);
            break;
        case RANKRESULT:
            rankResult(s, root);
            break;
        case UPDATE:
            UpdateRankResult(s,root);
            break;
        default:
            break;
        }
    }
}
void MyServer::writeEvent(TcpSocket *)
{

}
void MyServer::closeEvent(TcpSocket *s,short)
{
    auto it = _users.find(s->getUserName());
    if(it == _users.end())
    {
        _log->info("[{}:{}] loginout",s->getIp(),s->getPort());
    }
    else
    {
        //将用户从等待 rank的队列中删除
        std::unique_lock<std::mutex> lock1(_rankLock);
        int rank = _users[s->getUserName()]->getRank();
        auto it1 = _rankQueue.find(rank);
        if(it1 != _rankQueue.end())
        {
            _rankQueue.erase(it1);
        }

        printf("客户端退出，ip：%s, 端口：%d\n",s->getIp(),s->getPort());
        std::unique_lock<std::mutex> lock(_userLock);
        std::map<std::string, User*>::iterator it = _users.begin();
        while(it != _users.end())
        {
            if(it->second->getSocket() == s)
            {
                _users.erase(it);
                _log->info("用户{}[{}:{}] logout",it->second->getUserName(),s->getIp(),s->getPort());

                delete it->second;
                return;
            }
            it++;
        }
        _log->info("[{}:{}] logout", s->getIp(),s->getPort());
    }
}

void MyServer::writeData(TcpSocket *s,const Json::Value &inJson)
{
    std::string data = inJson.toStyledString();
    s->writeData(data.c_str(),data.length());
}


void MyServer::Register(TcpSocket *s, const Json::Value &inJson)//注册
{
    std::string userName = inJson["username"].asString();
    std::string passwd = inJson["passwd"].asString();

    //检测用户是否存在
    char sql[128] = {0};
    sprintf(sql,"select * from user where name = '%s' and passwd = '%s';",userName.c_str(),passwd.c_str());

    int result = OK;
    Json::Value outJson;
    bool ret = _db->db_select(sql,outJson);
    if(!ret)
    {
        result = ERROR;
        _log->error("Register select user error");
    }
    if(outJson.isMember("name"))   //用户存在，表示已经注册过了
    {
        result = USEREXIST;
    }
    else
    {
        memset(sql,0,sizeof(sql));
        sprintf(sql,"insert into user(name,passwd,rank) values('%s','%s',0);",userName.c_str(),passwd.c_str());
        ret = _db->db_exec(sql);
        if(!ret)
        {
            result = ERROR;
            _log->error("Register insert user error");
        }
        else
        {
            _log->info("Register user = {} succeed",userName);
        }
    }

    Json::Value json;
    json["cmd"] = REGISTER;
    json["result"] = result;

    writeData(s,json);
}

void MyServer::Login(TcpSocket *s, const Json::Value &inJson)//登录
{
    std::string userName = inJson["username"].asString();
    std::string passwd = inJson["passwd"].asString();

    int rank = 0;
    //检测用户是否存在
    char sql[128] = {0};
    sprintf(sql,"select * from user where name = '%s' and passwd = '%s';",userName.c_str(),passwd.c_str());

    int result = OK;
    Json::Value outJson;
    bool ret = _db->db_select(sql,outJson);
    if(!ret)
    {
        result = ERROR;
        _log->error("Login select user error");
    }
    if(outJson.isMember("name"))   //用户存在，表示已经注册过了
    {
        std::unique_lock<std::mutex> lock(_userLock);
        if(_users.find(userName) != _users.end())  //用户已经登陆
            result = USERLOGIN;
        else
        {
            int i = 0;
            rank = atoi(outJson["rank"][i].asString().c_str());
            User *user = new User(userName,passwd,rank,s);
            _users.insert(make_pair(userName,user));
            _log->info("用户{}[{}:{}] login",userName,s->getIp(),s->getPort());
            s->setUserName(userName);
        }
    }
    else
    {
        result = NAMEORPASSWD;
    }

    Json::Value json;
    json["cmd"] = LOGIN;
    json["result"] = result;
    json["username"] = userName;
    json["rank"] = _rankMap[rank];

    writeData(s,json);
}

void MyServer::singleGetQuestion(TcpSocket *s)//个人训练
{
    char sql[128] = {0};
    sprintf(sql,"select * from question order by rand() limit %d",QUESTION_NUM);

    int result = OK;
    Json::Value outJson;
    bool ret = _db->db_select(sql,outJson);
    if(!ret || outJson["question"].size() != QUESTION_NUM)
    {
        result = ERROR;
        _log->error("singleGetQuestion selcet question error");
    }

    Json::Value json;
    json["cmd"]  = SINGLE_GETQUESTION;
    json["result"] = result;
    json["question"] = outJson;

    _log->info("用户{}[{}:{}] 获取题目：{}\n",s->getUserName(),s->getIp(),s->getPort(),json.toStyledString());

    writeData(s,json);
}

void MyServer::initRankMap()//得分初始化
{
    char buf[100] = {0};
    int rank = 0;
    int num = 0;
    for(int i = 0; i < 100; i++)
    {
        if(i<9)
        {
            rank = i / 3;
            num  = i % 3;
            sprintf(buf,"青铜%d %d颗星",3-rank, num+1);
        }
        else if(9 <= i && i < 18)
        {
            rank = (i - 9) / 3;
            num = (i - 9) % 3;
            sprintf(buf,"白银%d %d颗星",3-rank, num+1);
        }
        else if(18 <= i && i < 34)
        {
            rank = (i - 18) / 4;
            num = (i - 18) % 4;
            sprintf(buf,"黄金%d %d颗星",4-rank, num+1);
        }
        else if(34 <= i && i < 50)
        {
            rank = (i - 34) / 4;
            num = (i - 34) % 4;
            sprintf(buf,"铂金%d %d颗星",4-rank, num+1);
        }
        else if(50 <= i && i < 75)
        {
            rank = (i - 50) / 5;
            num = (i - 50) % 5;
            sprintf(buf,"钻石%d %d颗星",5-rank, num+1);
        }
        else if(75 <= i && i < 100)
        {
            rank = (i - 75) / 5;
            num = (i - 75) % 5;
            sprintf(buf,"星曜%d %d颗星",5-rank, num+1);
        }

        _rankMap.insert(std::make_pair(i,buf));
    }
//    for(int i = 0; i < 100; i ++)
//    {
//        std::cout << i << " : " <<_rankMap[i] <<std::endl;
//    }
}

void MyServer::Rank(TcpSocket *s)
{
    TcpSocket *other = NULL;
    int rank = _users[s->getUserName()]->getRank();  //当前用户rank分

    std::unique_lock<std::mutex> lock(_rankLock);
    //查找同一段位对手
    std::map<int,TcpSocket *>::iterator it = _rankQueue.find(rank);
    if(it != _rankQueue.end())
    {
        other = it->second;
        _rankQueue.erase(it);
    }
    else
    {
        //查找其他段位对手，积分差值的绝对值小于5的都可以进行对决
        for(int i = 1; i <= 5; i++)
        {
            it = _rankQueue.find(rank + i);
            if(it != _rankQueue.end())
            {
                other = it->second;
                _rankQueue.erase(it);
                break;
            }
            it = _rankQueue.find(rank - i);
            if(it != _rankQueue.end())
            {
                other = it->second;
                _rankQueue.erase(it);
                break;
            }
        }
    }
    _log->info("rank分数{}",rank);
    if(other == NULL)  //没有匹配到用户
    {
        _rankQueue.insert(std::make_pair(rank, s));
        _log->info("用户{}[{}:{}] 获取题目",s->getUserName(),s->getIp(),s->getPort());
    }
    else  //找到
    {
        //开始对决
        startRank(s,other);
    }
}

void MyServer::startRank(TcpSocket *first, TcpSocket *second)
{
    char sql[100] = {0};
    sprintf(sql,"select * from question order by rand() limit %d",QUESTION_NUM);
    int result = OK;
    Json::Value outJson;
    bool ret = _db->db_select(sql,outJson);
    if(!ret || outJson["question"].size() != QUESTION_NUM)
    {
        result = ERROR;
        _log->error("startRank selcet question error");
    }

    Json::Value json;
    json["cmd"]  = RANK;
    json["result"] = result;
    json["question"] = outJson;
    //first user
    json["enemyName"] = second->getUserName();
    json["enemyRank"] = _rankMap[_users[second->getUserName()]->getRank()];
    json["enemyScore"] = 0;
    writeData(first,json);
    //second user
    json["enemyName"] = first->getUserName();
    json["enemyRank"] = _rankMap[_users[first->getUserName()]->getRank()];
    writeData(second,json);

    _log->info("获取 rank 题目：{}",json.toStyledString());

}

void MyServer::rankAnswerOneQuestion(const Json::Value &inJson)
{
    std::string enemyName = inJson["enemyName"].asString();
    User *user = _users[enemyName];

    Json::Value json;
    json["cmd"] = ANSWER;
    json["enemyscore"] = inJson["score"].asInt();
    json["enemyQuestionId"] = inJson["questionId"].asInt();

    writeData(user->getSocket(),json);
}

void MyServer::rankResult(TcpSocket *s, const Json::Value &inJson)
{
    std::unique_lock<std::mutex> lock(_userLock);
    User *user = _users[s->getUserName()];
    int score = inJson["score"].asInt();
    int enemyScore = inJson["enemyScore"].asInt();

    if(score < enemyScore)
    {
        user->setRank(user->getRank() - 1);
    }
    else if(score > enemyScore)
    {
        user->setRank(user->getRank() + 1);
    }
    Json::Value json;
    json["cmd"] = RANKRESULT;
    json["newRank"] = _rankMap[user->getRank()];
    writeData(s,json);
}

void MyServer::UpdateRankResult(TcpSocket *s,Json::Value &inJson)
{
    const char* Name = s->getUserName().c_str();
    User *user = _users[s->getUserName()];
    //printf("%s\n",Name);
    int score = user->getRank();
    //printf("%d\n",score);

    char sql[128] = {0};
    printf("%s -------------- %d\n",Name,score);
    sprintf(sql,"update user set rank = %d where name = '%s'",score,Name);
    printf("%s\n",sql);
    _db->db_exec(sql);
}







