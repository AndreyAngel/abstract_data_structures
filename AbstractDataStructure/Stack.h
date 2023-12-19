#pragma once

/// <summary>
/// ����
/// </summary>
/// <typeparam name="T"> ��� ��������� � ����� </typeparam>
template<typename T>
class Stack
{
	/// <summary>
	/// ��������� �� ������
	/// </summary>
	T* _array{ new T[3] };

	/// <summary>
	/// ���-�� ��������� � �����
	/// </summary>
	int _length{ 0 };

	/// <summary>
	/// �����������
	/// </summary>
	int _capacity{ 3 };

	/// <summary>
	/// ����������� ����������
	/// </summary>
	int const _magnificationFactor = 2;

public:

	/// <summary>
	/// ������ ��������� ������
	/// </summary>
	Stack();

	/// <summary>
	/// ������ ��������� ������
	/// </summary>
	/// <param name="capacity"> ����������� </param>
	Stack(int capacity);

	/// <summary>
	/// ������ ��������� ������
	/// </summary>
	/// <param name="length"> ����� ���������� ������� </param>
	/// <param name="capacity"> ����������� </param>
	/// <param name="array"> ��������� �� ������ </param>
	Stack(int length, int capacity, T* array);

	/// <summary>
	/// ���������� �������
	/// </summary>
	~Stack();

	/// <summary>
	/// �������� ������� � ����
	/// </summary>
	/// <param name="value"> ������� </param>
	void Push(T value);

	/// <summary>
	/// ������� �������� �� �����
	/// </summary>
	/// <returns> ������� </returns>
	T Pop();

	/// <summary>
	/// �������� ����
	/// </summary>
	void Clear();

	/// <summary>
	/// ������� ������� �����
	/// </summary>
	/// <returns> true, ���� ���� ����, ����� false </returns>
	bool IsEmpty();
};