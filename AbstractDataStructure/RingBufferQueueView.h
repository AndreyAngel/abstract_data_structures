#pragma once
#include "RingBufferQueue.h"
#include "IOConsoleHelper.h"

/// <summary>
/// Модель представления очереди на основе кольцевого буфера
/// </summary>
class RingBufferQueueView
{
	/// <summary>
	/// Указатель на очередь
	/// </summary>
	RingBufferQueue<int>* _queue;

	/// <summary>
	/// Размер буфера
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
	RingBufferQueueView(IOConsoleHelper* ioHelper);

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
