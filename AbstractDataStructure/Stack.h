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
	/// �������� ������� � ����
	/// </summary>
	void Push(T value);

	/// <summary>
	/// ������� �������� �� �����
	/// </summary>
	T Pop();

	/// <summary>
	/// �������� ����
	/// </summary>
	void Clear();

	/// <summary>
	/// ������� ������� �����
	/// </summary>
	bool IsEmpty();
};