#pragma once

template<typename T>
class Stack
{
	T* _array;
	int _length;
	int _capacity;
	int _magnificationFactor;

public:

	Stack();

	Stack(int capacity);

	Stack(int length, int capacity, T* array);

	~Stack();

	/// <summary>
	/// Добавить елемент в стек
	/// </summary>
	void Push(T value);

	/// <summary>
	/// Извлечь эелемент из стека
	/// </summary>
	T Pop();

	/// <summary>
	/// Очистить стек
	/// </summary>
	void Clear();

	/// <summary>
	/// Признак пустого стека
	/// </summary>
	bool IsEmpty();
};