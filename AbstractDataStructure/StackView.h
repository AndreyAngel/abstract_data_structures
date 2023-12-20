#pragma once
#include "IOConsoleHelper.h"
#include "Stack.h"

/// <summary>
/// ������ ������������� �����
/// </summary>
class StackView
{
	/// <summary>
	/// ����
	/// </summary>
	Stack<int>* _stack;

	/// <summary>
	/// ���-�� ���������
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
	StackView(IOConsoleHelper* ioHelper);

private:

	/// <summary>
	/// ���������������� ������ �������������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �������� ������� � ����
	/// </summary>
	void Push();

	/// <summary>
	/// ������� ������� �� �����
	/// </summary>
	void Pop();

	/// <summary>
	/// ���������� ����
	/// </summary>
	void Print();
};
