#ifndef BRAINSTORM_H
#define BRAINSTORM_H

#include <QDialog>
#include <QJsonArray>
#include <QJsonObject>
#include <QTimer>
#include "communicate.h"
#include <QDebug>
#define QUESTION_NUM  5
namespace Ui {
class BrainStorm;
}

class BrainStorm : public QDialog
{
    Q_OBJECT

public:
    explicit BrainStorm(Communicate *com,QJsonObject &json, QWidget *parent = nullptr);
    ~BrainStorm();

private:
    //获取题目
    void singleGetQuestion();
    //设置问题
    void singleSetQuestion();
    //单人训练答题
    void singleAnswerQuestion(int select);
    //设置得分
    void setEnemyStatus();
    void setSelfStatus();
    //设置问题
    void rankSetQuestion();

    //rank答题
    void rankAnswerQuestion(int select);

    //rank结果
    void rankSetResult(QJsonObject &json);

private slots:
    void on_singlepushButton_clicked();

    void on_Single_back_clicked();

    void on_Single_start_clicked();
    //单人训练从服务器接收题目
    void recvSingleQuestion(QJsonObject json);

    void singleTimeOut();
    void on_BackpushButton_clicked();

    void on_singleSelectButton1_clicked();

    void on_singleSelectButton2_clicked();

    void on_singleSelectButton3_clicked();

    void on_singleSelectButton4_clicked();

    void on_rankButton_clicked();

    //接受排位
    void Rank(QJsonObject json);

    void rankTimeOut();

    void on_rankSelectButton1_clicked();

    void on_rankSelectButton2_clicked();

    void on_rankSelectButton3_clicked();

    void on_rankSelectButton4_clicked();

    void on_BackpushButton_2_clicked();

private:
    Ui::BrainStorm *ui;
    Communicate *_com;

    QJsonObject _singleQuestion;
    int _currentSingleQuestion;  //当前回答题目的下标
    QTimer _singleTimer;         //个人训练定时器
    int _singleSec;             //个人训练答题时间
    int _singleScore;           //个人训练得分

    QJsonObject _rankQuestion;  //rank的题
    QString _enemyName;
    QString _enemyRank;
    int _enemyScore;

    int _rankSec;
    int _myScore;
    QString _userName;
    QString _userRank;
    int _currentRankQuestion;
    int _enemyRankQuestion;
    QTimer _rankTimer;
};

#endif // BRAINSTORM_H
