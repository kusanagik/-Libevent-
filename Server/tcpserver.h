#ifndef TCPSERVER_H
#define TCPSERVER_H

#include "thread.h"
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/util.h>
#include "tcpsocket.h"
class TcpSocket;
class TcpServer
{
    friend class TcpSocket;
public:
    TcpServer(int threadNum = 8);

    int listen(int port, const char* ip = NULL);

    void start();

protected:
    //监听回调函数，有客户端连接的时候，会调用这个函数
    static void listenCb(struct evconnlistener *, evutil_socket_t fd,struct sockaddr *clientAdd, int , void *data);
    void listenEvent(evutil_socket_t fd,struct sockaddr_in *clientAddr);

    virtual void connectEvent(TcpSocket *){}
    virtual void readEvent(TcpSocket *){}
    virtual void writeEvent(TcpSocket *){}
    virtual void closeEvent(TcpSocket *,short){}

private:
    int m_threadNum;
    Thread* m_threadPool;

    struct event_base *m_base;
    struct evconnlistener *m_listener;  //监听客户端连接
    int m_nextThread;
};

#endif // TCPSERVER_H
