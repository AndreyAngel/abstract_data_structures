#pragma once
#include "Stack.h"

/// <summary>
/// Очередь на базе двух стеков
/// </summary>
/// <typeparam name="T"> Тип элементов в очереди </typeparam>
template<typename T>
class StackBasedQueue
{
	/// <summary>
	/// Первый стек
	/// </summary>
	Stack<T>* _firstStack;

	/// <summary>
	/// Второй стек
	/// </summary>
	Stack<T>* _secondStack;

public:

	/// <summary>
	/// Создать экземпляр класса
	/// </summary>
	/// <param name="capacity"> Вместимость </param>
	StackBasedQueue(int capacity);

	/// <summary>
	/// Освободить память
	/// </summary>
	~StackBasedQueue();

	/// <summary>
	/// Добавить элемент
	/// </summary>
	/// <param name="value"> Элемент </param>
	void Enqueue(T value);

	/// <summary>
	/// Взять элемент
	/// </summary>
	/// <returns> Элемент </returns>
	T Dequeue();

	/// <summary>
	/// Получить признак пустой очереди
	/// </summary>
	/// <returns> true, если очередь пуста, иначе false </returns>
	bool IsEmpty();

	/// <summary>
	/// Очистить очередь
	/// </summary>
	void Clear();
};