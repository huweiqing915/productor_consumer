/*************************************************************************
	> File Name: main.cpp
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月15日 星期二 19时47分48秒
 ************************************************************************/

#include "WorkingQueue.h"
#include "ProducerThread.h"
#include "ConsumerThread.h"

int main(int argc, char *argv[])
{
	WorkingQueue Q;

	ProducerThread producer(&Q);
	ConsumerThread consumer(&Q);

	producer.start();
	consumer.start();

	producer.join();
	consumer.join();
	return 0;
}
