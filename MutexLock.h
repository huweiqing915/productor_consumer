/*************************************************************************
	> File Name: MutexLock.h
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月15日 星期二 16时29分01秒
 ************************************************************************/

#ifndef MUTEX_LOCK_H_
#define MUTEX_LOCK_H_

#include <pthread.h>

class Condition;

class MutexLock 
{
	public:
		friend class Condition;
		MutexLock();
		~MutexLock();

		void lock();
		void unlock();
	private:
		pthread_mutex_t mutex_;
};

#endif
