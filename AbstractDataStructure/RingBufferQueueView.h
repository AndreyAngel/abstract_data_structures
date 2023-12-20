#pragma once
#include "RingBufferQueue.h"
#include "IOConsoleHelper.h"

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

	/// <summary>
	/// ����� ��� ������ � ��������
	/// </summary>
	IOConsoleHelper* _ioHelper;

public:

	/// <summary>
	/// ������� ��������� ������ �������������
	/// </summary>
	/// <param name="ioHelper"> ����� ��� ������ � �������� </param>
	RingBufferQueueView(IOConsoleHelper* ioHelper);

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
