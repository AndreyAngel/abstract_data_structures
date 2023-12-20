#pragma once
#include "StackBasedQueue.h"
#include "IOConsoleHelper.h"

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

	/// <summary>
	/// ����� ��� ������ � ��������
	/// </summary>
	IOConsoleHelper* _ioHelper;

public:

	/// <summary>
	/// ������� ��������� ������ �������������
	/// </summary>
	/// <param name="ioHelper"> ����� ��� ������ � �������� </param>
	StackBasedQueueView(IOConsoleHelper* ioHelper);

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
