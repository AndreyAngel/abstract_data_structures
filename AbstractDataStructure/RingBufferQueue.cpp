#include "RingBufferQueue.h"

template<typename T>
inline RingBufferQueue<T>::RingBufferQueue(int capacity)
{
	_ringBuffer = new RingBuffer<T>(capacity);
}

template<typename T>
RingBufferQueue<T>::~RingBufferQueue()
{
	delete _ringBuffer;
}

template<typename T>
inline void RingBufferQueue<T>::Enqueue(T value)
{
	if (_ringBuffer->IsFull())
	{
		_ringBuffer->IncreaseCapacity();
	}

	_ringBuffer->Enqueue(value);
}

template<typename T>
inline T RingBufferQueue<T>::Dequeue()
{
	return _ringBuffer->Dequeue();
}

template<typename T>
bool RingBufferQueue<T>::IsEmpty()
{
	return _ringBuffer->IsEmpty();
}

template<typename T>
void RingBufferQueue<T>::Clear()
{
	_ringBuffer->Clear();
}
