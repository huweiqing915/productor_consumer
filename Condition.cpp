/*************************************************************************
	> File Name: Condition.cpp
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月15日 星期二 16时38分27秒
 ************************************************************************/

#include "Condition.h"
#include <stdexcept>

Condition::Condition(MutexLock *p_lock):p_lock_(p_lock)
{
	if(pthread_cond_init(&cond_, NULL) == -1)
		throw std::runtime_error("Init condition failed!!");
}

Condition::~Condition()
{
	pthread_cond_destroy(&cond_);
}

void Condition::wait()
{
	pthread_cond_wait(&cond_, &(p_lock_->mutex_));
}

void Condition::notify()
{
	pthread_cond_signal(&cond_);
}

void Condition::NotifyAll()
{
	pthread_cond_broadcast(&cond_);
}
