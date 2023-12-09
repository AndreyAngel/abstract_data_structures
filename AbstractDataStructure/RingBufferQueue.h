#pragma once

#include "RingBuffer.h"

/// <summary>
/// ������� �� ������ ���������� ������
/// </summary>
/// <typeparam name="T"> ��� ��������� � ������� </typeparam>
template<typename T>
class RingBufferQueue
{
	/// <summary>
	/// ��������� �����
	/// </summary>
	RingBuffer<T>* _ringBuffer;

public:

	/// <summary>
	/// ������� ��������� ������
	/// </summary>
	/// <param name="capacity"> ����������� </param>
	RingBufferQueue(int capacity);

	/// <summary>
	/// ���������� ������
	/// </summary>
	~RingBufferQueue();

	/// <summary>
	/// �������� �������
	/// </summary>
	/// <param name="value"> ������� </param>
	void Enqueue(T value);

	/// <summary>
	/// ������ �������
	/// </summary>
	/// <returns> ������� </returns>
	T Dequeue();

	/// <summary>
	/// ���������� ������� ������ �������
	/// </summary>
	/// <returns> true, ���� ������� �����, ����� false </returns>
	bool IsEmpty();

	/// <summary>
	/// �������� �������
	/// </summary>
	void Clear();
};