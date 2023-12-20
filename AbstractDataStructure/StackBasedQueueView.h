#pragma once
#include "StackBasedQueue.h"
#include "IOConsoleHelper.h"

/// <summary>
/// Модель представления очереди на базе двух стеков
/// </summary>
class StackBasedQueueView
{
	/// <summary>
	/// Указатель на очередь
	/// </summary>
	StackBasedQueue<int>* _queue;

	/// <summary>
	/// Размер очереди
	/// </summary>
	int _size;

	/// <summary>
	/// Класс для работы с консолью
	/// </summary>
	IOConsoleHelper* _ioHelper;

public:

	/// <summary>
	/// Создать экземпляр модели представления
	/// </summary>
	/// <param name="ioHelper"> Класс для работы с консолью </param>
	StackBasedQueueView(IOConsoleHelper* ioHelper);

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
