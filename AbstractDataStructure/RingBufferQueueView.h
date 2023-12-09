#pragma once

#include "RingBufferQueue.h"
#include "BaseView.h"

/// <summary>
/// Модель представления очереди на основе кольцевого буфера
/// </summary>
class RingBufferQueueView : BaseView
{
	/// <summary>
	/// Указатель на очередь
	/// </summary>
	RingBufferQueue<int>* _queue;

	/// <summary>
	/// Размер буфера
	/// </summary>
	int _size;

public:

	/// <summary>
	/// Создать экземпляр модели представления
	/// </summary>
	RingBufferQueueView();

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
