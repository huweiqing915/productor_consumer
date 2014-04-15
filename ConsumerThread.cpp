/*************************************************************************
	> File Name: ConsumerThread.cpp
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月15日 星期二 20时25分50秒
 ************************************************************************/

#include "ConsumerThread.h"
#include <iostream>
#include <stdlib.h>

ConsumerThread::ConsumerThread(WorkingQueue *p_queue):tid_(0), p_queue_(p_queue) { }

void *ConsumerThread::thread_func(void *arg)
{
	ConsumerThread* p_thread = static_cast<ConsumerThread*>(arg);
	p_thread->run();
	return NULL;
}

void ConsumerThread::start()
{
	pthread_create(&tid_, NULL, thread_func, this);
}

void ConsumerThread::run()
{
	while(true)
	{
		int num = p_queue_->consume();
		std::cout << "get a number:" << num << std::endl;
	}
}

void ConsumerThread::join()
{
	pthread_join(tid_, NULL);
}

ConsumerThread::~ConsumerThread() { }
