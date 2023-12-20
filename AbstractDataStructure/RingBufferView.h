#pragma once
#include "IOConsoleHelper.h"
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

	/// <summary>
	/// ����� ��� ������ � ��������
	/// </summary>
	IOConsoleHelper* _ioHelper;

public:

	/// <summary>
	/// ������� ��������� ������ �������������
	/// </summary>
	/// <param name="ioHelper"> ����� ��� ������ � �������� </param>
	RingBufferView(IOConsoleHelper* ioHelper);

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
