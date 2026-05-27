#ifndef THREAD_H
#define THREAD_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <event2/event.h>
#include <event2/event_struct.h>
#include <event2/event_compat.h>
class Thread
{
public:
    Thread();
    struct event_base *getBase();
public:
    void start();
    static void* work(void *arg);

    static void pipeRead(evutil_socket_t, short, void *);

    void run();
private:
    struct event_base *m_base;
    pthread_t m_pthreadId;

    int m_pipeReadFd;
    int m_pipeWriteFd;
    struct event m_pipeEvent;
};

#endif // THREAD_H
