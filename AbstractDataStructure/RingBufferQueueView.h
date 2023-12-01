#pragma once

#include "RingBufferQueue.h"

class RingBufferQueueView
{
	RingBufferQueue<int>* _queue;

	int _size;

public:

	RingBufferQueueView();

private:

	void Initialize();

	void Enqueue();

	void Dequeue();

	void Print();
};
