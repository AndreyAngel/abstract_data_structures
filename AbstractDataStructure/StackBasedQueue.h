#pragma once
#include "Stack.h"

template<typename T>
class StackBasedQueue
{
	Stack<T>* _firstStack;

	Stack<T>* _secondStack;

public:

	StackBasedQueue(int capacity);

	~StackBasedQueue();

	void Enqueue(T value);

	T Dequeue();

	bool IsEmpty();

	void Clear();
};