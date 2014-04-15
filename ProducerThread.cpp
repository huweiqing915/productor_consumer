/*************************************************************************
	> File Name: ProducerThread.cpp
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月15日 星期二 17时02分41秒
 ************************************************************************/

#include "ProducerThread.h"
#include <iostream>
#include <stdlib.h>

ProducerThread::ProducerThread(WorkingQueue* p_queue):tid_(0),p_queue_(p_queue)
{
	srand(time(NULL));
}

void *ProducerThread::thread_func(void *arg)
{
	ProducerThread* p_thread = static_cast<ProducerThread*>(arg);
	p_thread->run();
	return NULL;
}

void ProducerThread::start()
{
	pthread_create(&tid_, NULL, thread_func, this);
}

void ProducerThread::join()
{
	pthread_join(tid_, NULL);
}

void ProducerThread::run()
{
	while(true)
	{
		int tmp = rand()%1024;
		std::cout << "product a number:" << tmp << std::endl;
		p_queue_->product(tmp);
		sleep(2);
	}
}

ProducerThread::~ProducerThread()
{
}
