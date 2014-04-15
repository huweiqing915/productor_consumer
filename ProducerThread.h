/*************************************************************************
	> File Name: ProducerThread.h
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月15日 星期二 17时22分11秒
 ************************************************************************/

#ifndef PRODUCER_THREAD_H_
#define PRODUCER_THREAD_H_

#include <pthread.h>
#include "WorkingQueue.h"

class ProducerThread
{
	public:
		ProducerThread(WorkingQueue *);
		~ProducerThread();

		void start();
		void join();
	private:
		pthread_t tid_;
		static void* thread_func(void *);
		void run();
		WorkingQueue* p_queue_;
};

#endif
