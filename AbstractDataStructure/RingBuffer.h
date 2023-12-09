#pragma once

/// <summary>
/// ��������� �����
/// </summary>
/// <typeparam name="T"> ��� �������� � ������ </typeparam>
template<typename T>
class RingBuffer
{
	/// <summary>
	/// ������ ���������� ��� ��������� ��������
	/// </summary>
	int _head;

	/// <summary>
	/// ������ ����� ��� ���������� ��������
	/// </summary>
	int _tail;

	/// <summary>
	/// ������ ���������
	/// </summary>
	T* _array;

	/// <summary>
	/// ������ ������
	/// </summary>
	int _bufferSize;

	/// <summary>
	/// ���-�� ��������� � ������
	/// </summary>
	int _count;

public:
	/// <summary>
	/// ������� ��������� ������
	/// </summary>
	/// <param name="_length"> ������ ������ </param>
	RingBuffer(int _length);

	/// <summary>
	/// ���������� ������
	/// </summary>
	~RingBuffer();

	/// <summary>
	/// �������� �������
	/// </summary>
	/// <param name="value"> ������� </param>
	void Enqueue(T value);

	/// <summary>
	/// ����� �������
	/// </summary>
	T Dequeue();

	/// <summary>
	/// ���������� ������� ������� ������
	/// </summary>
	/// <returns> true, ���� ����� ����, ����� false </returns>
	bool IsEmpty();

	/// <summary>
	/// �������� �����
	/// </summary>
	void Clear();

private:
	/// <summary>
	/// �������� ��������� ������ ��������
	/// </summary>
	/// <param name="position"> ��������� ������� �������� </param>
	int NextPosition(int position);

	/// <summary>
	/// ���������� ������� ��������� ������������ ������ 
	/// </summary>
	/// <returns> true, ���� ����� ������, ����� false </returns>
	bool IsFull();
};