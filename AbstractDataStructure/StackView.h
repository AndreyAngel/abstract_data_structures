#pragma once

#include "Stack.h"

/// <summary>
/// Модель представления стека
/// </summary>
class StackView
{
	/// <summary>
	/// Стек
	/// </summary>
	Stack<int>* _stack;

	/// <summary>
	/// Кол-во элементов
	/// </summary>
	int _size;

public:

	/// <summary>
	/// Создать экземпляр модели представления
	/// </summary>
	StackView();

private:

	/// <summary>
	/// Инициализировать модель представления
	/// </summary>
	void Initialize();

	/// <summary>
	/// Добавить элемент в стек
	/// </summary>
	void Push();

	/// <summary>
	/// Извлечь элемент из стека
	/// </summary>
	void Pop();

	/// <summary>
	/// Отобразить стек
	/// </summary>
	void Print();
};
