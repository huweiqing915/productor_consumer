/*************************************************************************
	> File Name: WorkingQueue.h
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月15日 星期二 18时55分24秒
 ************************************************************************/

#ifndef WORKING_QUEUE_H_
#define WORKING_QUEUE_H_

#include <queue>
#include "MutexLock.h"
#include "Condition.h"

class WorkingQueue
{
	public:
		WorkingQueue();
		~WorkingQueue();

		int consume();
		void product(int);

	private:
		std::queue<int> queue_;
		MutexLock lock_;
		Condition cond_;
};

#endif
