/*************************************************************************
	> File Name: Condition.h
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月15日 星期二 16时38分38秒
 ************************************************************************/

#ifndef CONDITION_H_
#define CONDITION_H_

#include <pthread.h>
#include "MutexLock.h"

class Condition
{
	public:
		Condition(MutexLock *p_lock_);
		~Condition();

		void wait();  //pthread_cond_wait
		void notify();  //pthread_cond_signal
		void NotifyAll();  //pthread_cond_broadcast
	private:
		pthread_cond_t cond_;
		MutexLock *p_lock_;
};

#endif
