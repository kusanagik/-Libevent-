#ifndef MYSERVER_H
#define MYSERVER_H
#include "tcpserver.h"
#include "tcpsocket.h"
#include <spdlog/spdlog.h>
//#include "spdlog/sinks/stdout_color_sinks.h"
//#include "spdlog/sinks/rotating_file_sink.h"
#include "db.h"
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include "../common.h"
#include <string>
#include <map>
#include "user.h"
#include <iterator>
#include <iostream>

#define DEBUG
#define QUESTION_NUM  5
class MyServer : public TcpServer
{
public:
    MyServer();

    void connectEvent(TcpSocket *);
    void readEvent(TcpSocket *);
    void writeEvent(TcpSocket *);
    void closeEvent(TcpSocket *, short);

private:
    //发送数据
    void writeData(TcpSocket *s,const Json::Value &inJson);

    void Register(TcpSocket *s, const Json::Value &inJson);

    void Login(TcpSocket *s, const Json::Value &inJson);
    //个人训练获取题目
    void singleGetQuestion(TcpSocket *s);

    //初始化rank积分对照表
    void initRankMap();

    //进行排位
    void Rank(TcpSocket *s);

    //开始匹配
    void startRank(TcpSocket *first, TcpSocket *second);

    void rankAnswerOneQuestion(const Json::Value &inJson);

    void rankResult(TcpSocket *s, const Json::Value &inJson);

    void UpdateRankResult(TcpSocket *s,Json::Value &inJson);
private:
    std::shared_ptr<spdlog::logger> _log;

    DB *_db;
    //键是用户名，值是用户指针
    std::mutex _userLock;
    std::map<std::string, User *> _users;  //在线用户列表

    //key rank积分
    //值  对应的段位说明
    std::map<int, std::string> _rankMap;  //rank积分对比表

    //key : rank 分
    //value : 参与rank的用户socket
    std::mutex _rankLock;
    std::map<int, TcpSocket *> _rankQueue; //等待排位的队列
};

#endif // MYSERVER_H
