#pragma once

#include "RingBuffer.h"

/// <summary>
/// ������ ������������� ���������� ������
/// </summary>
class RingBufferView
{
	/// <summary>
	/// ��������� �� �����
	/// </summary>
	RingBuffer<int>* _ringBuffer;

	/// <summary>
	/// ������ �������
	/// </summary>
	int _size;

public:

	/// <summary>
	/// ������� ��������� ������ �������������
	/// </summary>
	RingBufferView();

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
