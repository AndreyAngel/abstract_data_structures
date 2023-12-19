#pragma once
#include "StackBasedQueue.h"

/// <summary>
/// ������ ������������� ������� �� ���� ���� ������
/// </summary>
class StackBasedQueueView
{
	/// <summary>
	/// ��������� �� �������
	/// </summary>
	StackBasedQueue<int>* _queue;

	/// <summary>
	/// ������ �������
	/// </summary>
	int _size;

public:

	/// <summary>
	/// ������� ��������� ������ �������������
	/// </summary>
	StackBasedQueueView();

private:

	/// <summary>
	/// ���������������� ������ �������������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �������� ������� � �������
	/// </summary>
	void Enqueue();

	/// <summary>
	/// ������� ������� �� �������
	/// </summary>
	void Dequeue();

	/// <summary>
	/// ���������� �������
	/// </summary>
	void Print();
};
