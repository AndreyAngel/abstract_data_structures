#pragma once

/// <summary>
/// Стек
/// </summary>
/// <typeparam name="T"> Тип элементов в стеке </typeparam>
template<typename T>
class Stack
{
	/// <summary>
	/// Указатель на массив
	/// </summary>
	T* _array{ new T[3] };

	/// <summary>
	/// Кол-во элементов в стеке
	/// </summary>
	int _length{ 0 };

	/// <summary>
	/// Вместимость
	/// </summary>
	int _capacity{ 3 };

	/// <summary>
	/// Коэффициент увеличения
	/// </summary>
	int const _magnificationFactor = 2;

public:

	/// <summary>
	/// Создаёт экземпляр класса
	/// </summary>
	Stack();

	/// <summary>
	/// Создаёт экземпляр класса
	/// </summary>
	/// <param name="capacity"> Вместимость </param>
	Stack(int capacity);

	/// <summary>
	/// Создаёт экземпляр класса
	/// </summary>
	/// <param name="length"> Длина переданног массива </param>
	/// <param name="capacity"> Вместимость </param>
	/// <param name="array"> Указатель на массив </param>
	Stack(int length, int capacity, T* array);

	/// <summary>
	/// Освободить ресурсы
	/// </summary>
	~Stack();

	/// <summary>
	/// Добавить елемент в стек
	/// </summary>
	/// <param name="value"> Элемент </param>
	void Push(T value);

	/// <summary>
	/// Извлечь эелемент из стека
	/// </summary>
	/// <returns> Элемент </returns>
	T Pop();

	/// <summary>
	/// Очистить стек
	/// </summary>
	void Clear();

	/// <summary>
	/// Признак пустого стека
	/// </summary>
	/// <returns> true, если стек пуст, иначе false </returns>
	bool IsEmpty();
};