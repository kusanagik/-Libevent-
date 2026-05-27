#ifndef COMMUNICATE_H
#define COMMUNICATE_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QHostAddress>
#include <QJsonArray>
#include <QDebug>
#include "../common.h"
class Communicate : public QObject
{
    Q_OBJECT
public:
    explicit Communicate(QObject *parent = nullptr);
    void writeData(const QJsonObject &json);

signals:
    void rstResult(int );

    void login(QJsonObject json);

    void recvSingleQuestion(QJsonObject json);

    void rank(QJsonObject json);
private slots:
    void readData();

private:
    QTcpSocket s;

};

#endif // COMMUNICATE_H
