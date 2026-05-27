#include "tcpsocket.h"

TcpServer *TcpSocket::m_tcpserver = NULL;

TcpSocket::TcpSocket(TcpServer *tcpserver,struct bufferevent *bev,char *ip,u_int16_t port)
{
    m_tcpserver = tcpserver;
    m_bev = bev;
    m_ip = ip;
    m_port = port;
}

void TcpSocket::readEventCb(struct bufferevent *, void *ctx)
{
    TcpSocket *s = (TcpSocket *)ctx;
    m_tcpserver->readEvent(s);
}

void TcpSocket::writeEventCb(struct bufferevent *, void *ctx)
{
    TcpSocket *s = (TcpSocket *)ctx;
    m_tcpserver->writeEvent(s);
}

void TcpSocket::closeEventCb(struct bufferevent *, short what, void *ctx)
{
    TcpSocket *s = (TcpSocket *)ctx;
    m_tcpserver->closeEvent(s,what);

    delete s;
}

char *TcpSocket::getIp()
{
    return m_ip;
}
u_int16_t TcpSocket::getPort()
{
    return m_port;
}

int TcpSocket::readData(void *data, int size)
{
    return bufferevent_read(m_bev,data,size);
}
int TcpSocket::writeData(const void *data, int size)
{
    return bufferevent_write(m_bev,data,size);
}

void TcpSocket::setUserName(std::string name)
{
    _userName = name;
}
std::string TcpSocket::getUserName()
{
    return _userName;
}
