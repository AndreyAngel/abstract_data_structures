#pragma once
#include "StackBasedQueue.h"
#include "BaseView.h"

/// <summary>
/// Модель представления очереди на базе двух стеков
/// </summary>
class StackBasedQueueView : BaseView
{
	/// <summary>
	/// Указатель на очередь
	/// </summary>
	StackBasedQueue<int>* _queue;

	/// <summary>
	/// Размер очереди
	/// </summary>
	int _size;

public:

	/// <summary>
	/// Создать экземпляр модели представления
	/// </summary>
	StackBasedQueueView();

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
