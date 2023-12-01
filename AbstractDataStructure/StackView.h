#pragma once

#include "Stack.h"

class StackView
{
	Stack<int>* _stack;

public:

	StackView();

private:

	void Initialize();

	void Push();

	void Pop();

	void Print();
};
