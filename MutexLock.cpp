/*************************************************************************
	> File Name: MutexLock.cpp
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月15日 星期二 16时29分12秒
 ************************************************************************/

#include "MutexLock.h"
#include <stdexcept>
#include "Condition.h"

MutexLock::MutexLock()
{
	if(pthread_mutex_init(&mutex_, NULL) == -1)
		throw std::runtime_error("Init lock failed!!");
}

MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&mutex_);
}

void MutexLock::lock()
{
	pthread_mutex_lock(&mutex_);
}

void MutexLock::unlock()
{
	pthread_mutex_unlock(&mutex_);
}
