#include "brainstorm.h"
#include "ui_brainstorm.h"

BrainStorm::BrainStorm(Communicate *com, QJsonObject &json, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrainStorm)
{
    ui->setupUi(this);
    _com = com;

    _userName = json["username"].toString();
    _userRank = json["rank"].toString();

    connect(&_singleTimer,SIGNAL(timeout()),this,SLOT(singleTimeOut()));
    connect(&_rankTimer,SIGNAL(timeout()),this,SLOT(rankTimeOut()));
    connect(_com,SIGNAL(recvSingleQuestion(QJsonObject)),this,SLOT(recvSingleQuestion(QJsonObject)));
    connect(_com,SIGNAL(rank(QJsonObject)),this,SLOT(Rank(QJsonObject)));
}

BrainStorm::~BrainStorm()
{
    delete ui;
}

void BrainStorm::singleGetQuestion()
{
    QJsonObject json;
    json["cmd"] = SINGLE_QUESTION;
    _com->writeData(json);
}


//进入个人训练
void BrainStorm::on_singlepushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->single_menu);
}

void BrainStorm::on_Single_back_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->mainMenu);
}
//开始答题
void BrainStorm::on_Single_start_clicked()
{
    singleGetQuestion();
}
//设置问题
void BrainStorm::singleSetQuestion()
{
    //题目结束
    if(_currentSingleQuestion == QUESTION_NUM)
    {
        ui->singleResult->setText("恭喜全部答对");
        QString str = QString("本次得分：%1").arg(_singleScore);
        ui->singleScore->setText(str);
        ui->stackedWidget->setCurrentWidget(ui->single_score);
        _singleTimer.stop();
        return;
    }

    ui->Question->setText(_singleQuestion["question"].toArray().at(_currentSingleQuestion).toString());
    ui->singleSelectButton1->setText(_singleQuestion["selection1"].toArray().at(_currentSingleQuestion).toString());
    ui->singleSelectButton2->setText(_singleQuestion["selection2"].toArray().at(_currentSingleQuestion).toString());
    ui->singleSelectButton3->setText(_singleQuestion["selection3"].toArray().at(_currentSingleQuestion).toString());
    ui->singleSelectButton4->setText(_singleQuestion["selection4"].toArray().at(_currentSingleQuestion).toString());
}
//接受题目
void BrainStorm::recvSingleQuestion(QJsonObject json)
{
    _singleQuestion = json;
    _currentSingleQuestion = 0;
    _singleSec = 10;
    _singleScore = 0;
    singleSetQuestion();

    //开启定时器
    _singleTimer.start(1000);
    ui->stackedWidget->setCurrentWidget(ui->single_running);
}

void BrainStorm::singleTimeOut()
{
    -- _singleSec;
    if(_singleSec == 0)
    {
        ui->singleResult->setText("回答错误");
        QString str = QString("本次得分：%1").arg(_singleScore);
        ui->singleScore->setText(str);
        _singleTimer.stop();
        ui->stackedWidget->setCurrentWidget(ui->single_score);
    }
    ui->lcdNumber->display(_singleSec);
}

void BrainStorm::on_BackpushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->mainMenu);
}


//单人训练答题
void BrainStorm::singleAnswerQuestion(int select)
{
    if(select == _singleQuestion["answer"].toArray().at(_currentSingleQuestion).toString().toInt())
    {
        _singleScore += 20*_singleSec;
        _currentSingleQuestion++;
        singleSetQuestion(); //设置下一题
        _singleSec = 10;
        _singleTimer.stop();
        ui->lcdNumber->display(_singleSec);
        _singleTimer.start(1000);
    }
    else
    {
        ui->singleResult->setText("回答错误");
        QString str = QString("本次得分：%1").arg(_singleScore);
        ui->singleScore->setText(str);
        ui->stackedWidget->setCurrentWidget(ui->single_score);
        _singleTimer.stop();
    }
}

void BrainStorm::on_singleSelectButton1_clicked()
{
    singleAnswerQuestion(1);
}

void BrainStorm::on_singleSelectButton2_clicked()
{
    singleAnswerQuestion(2);
}

void BrainStorm::on_singleSelectButton3_clicked()
{
    singleAnswerQuestion(3);
}

void BrainStorm::on_singleSelectButton4_clicked()
{
    singleAnswerQuestion(4);
}

// ----------------------rank----------------------
void BrainStorm::on_rankButton_clicked()
{
    QJsonObject json;
    json["cmd"] = RANK;
    _com->writeData(json);
    ui->stackedWidget->setCurrentWidget(ui->rank_wait);
}

//接受排位
void BrainStorm::Rank(QJsonObject json)
{
    qDebug("--------------------");
    int cmd = json["cmd"].toInt();
    if(cmd == RANK)
    {
        _rankQuestion = json["question"].toObject();
        _enemyName = json["enemyName"].toString();
        _enemyRank = json["enemyRank"].toString();
        _enemyScore = json["enemyScore"].toInt();

        _rankSec = 10;
        _myScore = 0;
        ui->lcdNumber_2->display(_rankSec);
        _currentRankQuestion = 0;

        setEnemyStatus();
        setSelfStatus();
        rankSetQuestion();

        _rankTimer.start(1000);
        ui->stackedWidget->setCurrentWidget(ui->rank_running);
    }
    else if(cmd == ANSWER)
    {
        _enemyScore = json["enemyscore"].toInt();
        _enemyRankQuestion = json["enemyQuestionId"].toInt();
        setEnemyStatus();

        if(_currentRankQuestion == _enemyRankQuestion)
        {
            _rankSec = 10;
            _rankTimer.stop();
            ui->lcdNumber_2->display(_rankSec);
            _rankTimer.start(1000);
            rankSetQuestion();
        }
    }
    else if(cmd == RANKRESULT)
    {
        rankSetResult(json);
    }
}

void BrainStorm::setEnemyStatus()
{
    QString str = QString("%1(%2): %3").arg(_enemyName, -5).arg(_enemyRank).arg(_enemyScore);
    ui->enemyStatus->setText(str);
}
void BrainStorm::setSelfStatus()
{
    QString str = QString("%1(%2): %3").arg(_userName, -5).arg(_userRank).arg(_myScore);
    ui->selfStatus->setText(str);
}
void BrainStorm::rankSetQuestion()
{
    ui->rankQuestion->setText(_rankQuestion["question"].toArray().at(_currentRankQuestion).toString());
    ui->rankSelectButton1->setText(_rankQuestion["selection1"].toArray().at(_currentRankQuestion).toString());
    ui->rankSelectButton2->setText(_rankQuestion["selection2"].toArray().at(_currentRankQuestion).toString());
    ui->rankSelectButton3->setText(_rankQuestion["selection3"].toArray().at(_currentRankQuestion).toString());
    ui->rankSelectButton4->setText(_rankQuestion["selection4"].toArray().at(_currentRankQuestion).toString());

    ui->rankSelectButton1->setEnabled(true);
    ui->rankSelectButton2->setEnabled(true);
    ui->rankSelectButton3->setEnabled(true);
    ui->rankSelectButton4->setEnabled(true);

    ui->rankSelectButton1->setStyleSheet("");
    ui->rankSelectButton2->setStyleSheet("");
    ui->rankSelectButton3->setStyleSheet("");
    ui->rankSelectButton4->setStyleSheet("");

    if(_currentRankQuestion == QUESTION_NUM)
    {
        _rankTimer.stop();
        //将结果发送给服务器

        QJsonObject json;
        json["cmd"] = RANKRESULT;
        json["score"] = _myScore;
        json["enemyName"] = _enemyName;
        json["enemyScore"] = _enemyScore;

        _com->writeData(json);
    }
}

void BrainStorm::rankTimeOut()
{
    _rankSec--;
    if(_rankSec == 0)
    {
        if(ui->rankSelectButton1->isEnabled())
        {
            _currentRankQuestion++;
        }
        rankSetQuestion();
        _rankSec = 10;
    }
    ui->lcdNumber_2->display(_rankSec);
}

void BrainStorm::rankAnswerQuestion(int select)
{
    //计算得分
    if(select == _rankQuestion["answer"].toArray().at(_currentRankQuestion).toString().toInt())
    {
        _myScore += 20*_rankSec;
    }
    setSelfStatus();
    _currentRankQuestion++;

    //判断是否跳到下一题
    if(_currentRankQuestion == _enemyRankQuestion)
    {
        _rankSec = 10;
        _rankTimer.stop();
        ui->lcdNumber_2->display(_rankSec);
        _rankTimer.start(1000);
        rankSetQuestion();
    }

    QJsonObject json;
    json["cmd"] = ANSWER;
    json["enemyName"] = _enemyName;
    json["score"] = _myScore;
    json["questionId"] = _currentRankQuestion;

    _com->writeData(json);
}

void BrainStorm::rankSetResult(QJsonObject &json)
{
    QString newRank = json["newRank"].toString();
    if(_myScore == _enemyScore)
    {
        ui->rankResult->setText("平局");
    }
    if(_myScore > _enemyScore)
    {
        ui->rankResult->setText("胜利");
    }
    if(_myScore < _enemyScore)
    {
        ui->rankResult->setText("失败");
    }
    QString str = QString("%1 ----> %2").arg(_userRank).arg(newRank);
    ui->Newrank->setText(str);
    _userRank = newRank;

    //------------------------

    QJsonObject newjson;
    newjson["cmd"] = UPDATE;
    //newjson["username"] = _userName;
    //newjson["myScore"] = _userRank;
    //qDebug("%s--------%s",qPrintable(_userName),qPrintable(_userRank));
    _com->writeData(newjson);

    ui->stackedWidget->setCurrentWidget(ui->rank_result);
}

void BrainStorm::on_rankSelectButton1_clicked()
{
    ui->rankSelectButton1->setStyleSheet("background-color: blue");
    ui->rankSelectButton1->setEnabled(false);
    ui->rankSelectButton2->setEnabled(false);
    ui->rankSelectButton3->setEnabled(false);
    ui->rankSelectButton4->setEnabled(false);
    rankAnswerQuestion(1);
}

void BrainStorm::on_rankSelectButton2_clicked()
{
    ui->rankSelectButton2->setStyleSheet("background-color: blue");
    ui->rankSelectButton1->setEnabled(false);
    ui->rankSelectButton2->setEnabled(false);
    ui->rankSelectButton3->setEnabled(false);
    ui->rankSelectButton4->setEnabled(false);
    rankAnswerQuestion(2);
}

void BrainStorm::on_rankSelectButton3_clicked()
{
    ui->rankSelectButton3->setStyleSheet("background-color: blue");
    ui->rankSelectButton1->setEnabled(false);
    ui->rankSelectButton2->setEnabled(false);
    ui->rankSelectButton3->setEnabled(false);
    ui->rankSelectButton4->setEnabled(false);
    rankAnswerQuestion(3);
}

void BrainStorm::on_rankSelectButton4_clicked()
{
    ui->rankSelectButton4->setStyleSheet("background-color: blue");
    ui->rankSelectButton1->setEnabled(false);
    ui->rankSelectButton2->setEnabled(false);
    ui->rankSelectButton3->setEnabled(false);
    ui->rankSelectButton4->setEnabled(false);
    rankAnswerQuestion(4);
}

void BrainStorm::on_BackpushButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->mainMenu);
}
