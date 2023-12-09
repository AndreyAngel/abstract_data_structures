#pragma once
#include "Stack.h"

/// <summary>
/// ������� �� ���� ���� ������
/// </summary>
/// <typeparam name="T"> ��� ��������� � ������� </typeparam>
template<typename T>
class StackBasedQueue
{
	/// <summary>
	/// ������ ����
	/// </summary>
	Stack<T>* _firstStack;

	/// <summary>
	/// ������ ����
	/// </summary>
	Stack<T>* _secondStack;

public:

	/// <summary>
	/// ������� ��������� ������
	/// </summary>
	/// <param name="capacity"> ����������� </param>
	StackBasedQueue(int capacity);

	/// <summary>
	/// ���������� ������
	/// </summary>
	~StackBasedQueue();

	/// <summary>
	/// �������� �������
	/// </summary>
	/// <param name="value"> ������� </param>
	void Enqueue(T value);

	/// <summary>
	/// ����� �������
	/// </summary>
	/// <returns> ������� </returns>
	T Dequeue();

	/// <summary>
	/// �������� ������� ������ �������
	/// </summary>
	/// <returns> true, ���� ������� �����, ����� false </returns>
	bool IsEmpty();

	/// <summary>
	/// �������� �������
	/// </summary>
	void Clear();
};