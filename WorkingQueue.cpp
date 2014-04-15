/*************************************************************************
	> File Name: WorkingQueue.cpp
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月15日 星期二 20时39分29秒
 ************************************************************************/

#include "WorkingQueue.h"
#include <iostream> 

WorkingQueue::WorkingQueue():queue_(), lock_(), cond_(&lock_) 
{
	std::cout << "WorkingQueue constructor success!" << std::endl;
}

int WorkingQueue::consume()
{
	lock_.lock();
	while(queue_.empty())
	{
		cond_.wait();
	}
	int num = queue_.front();
	queue_.pop();
	lock_.unlock();
	return num;
}

void WorkingQueue::product(int num)
{
	lock_.lock();
	queue_.push(num);
	cond_.notify();
	lock_.unlock();
}


WorkingQueue::~WorkingQueue() { }
