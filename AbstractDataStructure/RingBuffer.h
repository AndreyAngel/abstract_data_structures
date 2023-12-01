#pragma once

template<typename T>
class RingBuffer
{
	T* _head;

	T* _tail;

	T* _array;

	int _bufferSize;

	int _count = 0;

public:
	RingBuffer(int _length);

	~RingBuffer();

	void Enqueue(T value);

	T Dequeue();

	bool IsEmpty();

	void Clear();

private:
	T* NextPosition(int* position);

	bool IsFull();
};