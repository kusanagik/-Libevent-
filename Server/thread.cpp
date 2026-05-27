#include "thread.h"

Thread::Thread()
{
    m_base = event_base_new();
    if(!m_base)
    {
        printf("Could not create an event_base:exiting\n");
        exit(-1);
    }

    int fd[2];
    if(pipe(fd) == -1)
    {
        perror("pipe");
        exit(-1);
    }
    m_pipeReadFd = fd[0];
    m_pipeWriteFd = fd[1];

    //让管道事件监听管道的读端SZfffDSdw
    //如果监听到 管道的读端有数据可读
    event_set(&m_pipeEvent, m_pipeReadFd, EV_READ | EV_PERSIST, pipeRead, this);

    //将事件添加到 m_base集合中
    event_base_set(m_base, &m_pipeEvent);

    //开启事件
    event_add(&m_pipeEvent,0);

}


void Thread::pipeRead(evutil_socket_t, short, void *)
{

}
void Thread::start()
{
    pthread_create(&m_pthreadId,NULL,work,this);

    pthread_detach(m_pthreadId);
}
void* Thread::work(void *arg)
{
    Thread *p = (Thread *)arg;
    p->run();

    return NULL;
}

void Thread::run()
{
    //监听base集合事件
    event_base_dispatch(m_base);
    event_base_free(m_base);
}

struct event_base *Thread::getBase()
{
    return m_base;
}
