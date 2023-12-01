#pragma once

#include "RingBuffer.h"

template<typename T>
class RingBufferQueue
{
	RingBuffer<T>* _ringBuffer;

public:

	RingBufferQueue(int capacity);

	~RingBufferQueue();

	void Enqueue(T value);

	T Dequeue();

	bool IsEmpty();

	void Clear();
};