#pragma once
#include "StackBasedQueue.h"

class StackBasedQueueView
{
	StackBasedQueue<int>* _queue;

	int _size;

public:

	StackBasedQueueView();

private:

	void Initialize();

	void Enqueue();

	void Dequeue();

	void Print();
};
