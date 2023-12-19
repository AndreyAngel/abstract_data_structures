#pragma once

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

public:

	/// <summary>
	/// ������� ��������� ������ �������������
	/// </summary>
	StackView();

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
