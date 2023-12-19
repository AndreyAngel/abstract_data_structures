#pragma once

#include "RingBuffer.h"

/// <summary>
/// Модель представления кольцевого буфера
/// </summary>
class RingBufferView
{
	/// <summary>
	/// Указатель на буфер
	/// </summary>
	RingBuffer<int>* _ringBuffer;

	/// <summary>
	/// Размер очереди
	/// </summary>
	int _size;

public:

	/// <summary>
	/// Создать экземпляр модкли представления
	/// </summary>
	RingBufferView();

private:

	/// <summary>
	/// Инициализировать модель представления
	/// </summary>
	void Initialize();

	/// <summary>
	/// Добавить элемент в очередь
	/// </summary>
	void Enqueue();

	/// <summary>
	/// Извлечь элемент из очереди
	/// </summary>
	void Dequeue();

	/// <summary>
	/// Отобразить очередь
	/// </summary>
	void Print();
};
