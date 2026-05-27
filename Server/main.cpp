#include <iostream>
#include "thread.h"
#include "tcpserver.h"
#include "myserver.h"
using namespace std;
int main()
{
    MyServer s;
    s.listen(9999);
    s.start();
    return 0;
}
