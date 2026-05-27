#ifndef USER_H
#define USER_H
#include "tcpsocket.h"
#include <string>

class User
{
public:
    User(std::string n, std::string p, int rank, TcpSocket *s);

    TcpSocket *getSocket();

    const char *getUserName();

    int getRank();

    void setRank(int rank);
private:
    std::string _userName;
    std::string _passwd;
    int _rank;

    TcpSocket *_s;
};

#endif // USER_H
