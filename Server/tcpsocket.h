#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include "tcpserver.h"
#include <string>
class TcpServer;
class TcpSocket
{
public:
    TcpSocket(TcpServer *tcpserver,struct bufferevent *bev,char *ip,u_int16_t port);
    //可读事件回调函数
    static void readEventCb(struct bufferevent *, void *ctx);
    //可写事件回调函数
    static void writeEventCb(struct bufferevent *, void *ctx);
    //异常事件回调函数
    static void closeEventCb(struct bufferevent *, short what, void *ctx);

    char *getIp();
    u_int16_t getPort();

    void setUserName(std::string name);
    std::string getUserName();

    //读写事件
    int readData(void *data, int size);
    int writeData(const void *data, int size);
private:
    static TcpServer *m_tcpserver;
    struct bufferevent *m_bev;
    char *m_ip;
    u_int16_t m_port;

    std::string _userName;
};

#endif // TCPSOCKET_H
