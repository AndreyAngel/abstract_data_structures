#include "StackBasedQueue.h"

template<typename T>
StackBasedQueue<T>::StackBasedQueue(int capacity)
{
	_firstStack = new Stack<int>(capacity);
	_secondStack = new Stack<int>(capacity);
}

template<typename T>
StackBasedQueue<T>::~StackBasedQueue()
{
	delete _firstStack;
	delete _secondStack;
}

template<typename T>
void StackBasedQueue<T>::Enqueue(T value)
{
	_firstStack->Push(value);
}

template<typename T>
T StackBasedQueue<T>::Dequeue()
{
	if (_secondStack->IsEmpty())
	{
		_secondStack->Push(_firstStack->Pop());
	}

	return _secondStack->Pop();
}

template<typename T>
bool StackBasedQueue<T>::IsEmpty()
{
	return _firstStack->IsEmpty() && _secondStack->IsEmpty();
}

template<typename T>
void StackBasedQueue<T>::Clear()
{
	_firstStack->Clear();
	_secondStack->Clear();
}
