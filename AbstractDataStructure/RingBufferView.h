#pragma once

#include "RingBuffer.h"

class RingBufferView
{
	RingBuffer<int>* _ringBuffer;

	int _size;

public:

	RingBufferView();

private:

	void Initialize();

	void Enqueue();

	void Dequeue();

	void Print();
};
