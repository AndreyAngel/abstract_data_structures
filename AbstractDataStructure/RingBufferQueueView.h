#pragma once

#include "RingBufferQueue.h"

/// <summary>
/// ������ ������������� ������� �� ������ ���������� ������
/// </summary>
class RingBufferQueueView
{
	/// <summary>
	/// ��������� �� �������
	/// </summary>
	RingBufferQueue<int>* _queue;

	/// <summary>
	/// ������ ������
	/// </summary>
	int _size;

public:

	/// <summary>
	/// ������� ��������� ������ �������������
	/// </summary>
	RingBufferQueueView();

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
