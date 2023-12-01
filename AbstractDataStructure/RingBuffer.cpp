#include "RingBuffer.h"
#include <iostream>

template<typename T>
RingBuffer<T>::RingBuffer(int bufferSize)
{
	_bufferSize = bufferSize;
	_array = new T[bufferSize];
	_tail = _array;
	_head = _array;
}

template<typename T>
RingBuffer<T>::~RingBuffer()
{
	/*delete _head;
	delete _tail;
	delete[] _array;
	_array = nullptr;
	_bufferSize = 0;
	_count = 0;*/
}

template<typename T>
T* RingBuffer<T>::NextPosition(int* position)
{
	if (position == _array + _bufferSize - 1)
	{
		position = _array;
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
	return _tail == _head && !IsFull();
}

template<typename T>
void RingBuffer<T>::Enqueue(T value)
{
	*_tail = value;

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
		throw _exception();
	}

	T result = *_head;
	*_head = NULL;
	_head = NextPosition(_head);
	_count--;

	return result;
}

template<typename T>
void RingBuffer<T>::Clear()
{
	delete[] _array;
	/*_head = nullptr;
	_tail = nullptr;*/
	_count = 0;
}
