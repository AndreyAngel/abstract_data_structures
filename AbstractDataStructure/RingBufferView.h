#pragma once
#include "IOConsoleHelper.h"
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

	/// <summary>
	/// Класс для работы с консолью
	/// </summary>
	IOConsoleHelper* _ioHelper;

public:

	/// <summary>
	/// Создать экземпляр модкли представления
	/// </summary>
	/// <param name="ioHelper"> Класс для работы с консолью </param>
	RingBufferView(IOConsoleHelper* ioHelper);

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
