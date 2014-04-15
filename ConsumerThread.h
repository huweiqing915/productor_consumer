/*************************************************************************
	> File Name: ConsumerThread.h
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月15日 星期二 17时02分57秒
 ************************************************************************/

#ifndef CONSUMER_THREAD_H_
#define CONSUMER_THREAD_H_

#include <pthread.h>
#include "WorkingQueue.h"

class ConsumerThread
{
	public:
		ConsumerThread(WorkingQueue* p_queue);
		~ConsumerThread();

		void start();
		void join();
	private:
		pthread_t tid_;
		static void *thread_func(void *);
		void run();
		WorkingQueue* p_queue_;
};

#endif

