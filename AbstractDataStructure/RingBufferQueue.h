#pragma once

#include "RingBuffer.h"

/// <summary>
/// Очередь на основе кольцевого буфера
/// </summary>
/// <typeparam name="T"> Тип элементов в очереди </typeparam>
template<typename T>
class RingBufferQueue
{
	/// <summary>
	/// Кольцевой буфер
	/// </summary>
	RingBuffer<T>* _ringBuffer;

public:

	/// <summary>
	/// Создать экземпляр класса
	/// </summary>
	/// <param name="capacity"> Вместимость </param>
	RingBufferQueue(int capacity);

	/// <summary>
	/// Освободить память
	/// </summary>
	~RingBufferQueue();

	/// <summary>
	/// Добавить элемент
	/// </summary>
	/// <param name="value"> Элемент </param>
	void Enqueue(T value);

	/// <summary>
	/// Взяять элемент
	/// </summary>
	/// <returns> Элемент </returns>
	T Dequeue();

	/// <summary>
	/// Возвращает признак пустой очереди
	/// </summary>
	/// <returns> true, если очередь пуста, иначе false </returns>
	bool IsEmpty();

	/// <summary>
	/// Очистить очередь
	/// </summary>
	void Clear();
};