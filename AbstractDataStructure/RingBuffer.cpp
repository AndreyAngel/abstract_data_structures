#include "RingBuffer.h"
#include <iostream>

template<typename T>
RingBuffer<T>::RingBuffer(int bufferSize)
{
	_bufferSize = bufferSize;
	_array = new T[bufferSize];
}

template<typename T>
RingBuffer<T>::~RingBuffer()
{
	Clear();
	_array = nullptr;
	_bufferSize = 0;
}

template<typename T>
int RingBuffer<T>::NextPosition(int position)
{
	if (position == _bufferSize - 1)
	{
		position = 0;
	}
	else
	{
		position++;
	}

	return position;
}

template<typename T>
bool RingBuffer<T>::IsFull()
{
	return _count == _bufferSize;
}

template<typename T>
bool RingBuffer<T>::IsEmpty()
{
	return _count == 0;
}

template<typename T>
void RingBuffer<T>::Enqueue(T value)
{
	_array[_tail] = value;

	if (_head == _tail && !IsEmpty())
	{
		_head = NextPosition(_head);
	}

	_tail = NextPosition(_tail);
	
	if (_count != _bufferSize)
	{
		_count++;
	}
}

template<typename T>
T RingBuffer<T>::Dequeue()
{
	if (IsEmpty())
	{
		throw std::exception();
	}

	T result = _array[_head];
	//TODO: nullptr
	_head = NextPosition(_head);
	_count--;

	return result;
}

template<typename T>
void RingBuffer<T>::Clear()
{
	for (int i = 0; i < _count; i++)
	{
		_array[i] = NULL;
	}

	_head = 0;
	_tail = 0;
	_count = 0;
}
