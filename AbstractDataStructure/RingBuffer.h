#pragma once

/// <summary>
/// Кольцевой буфер
/// </summary>
/// <typeparam name="T"> Тип элеметов в буфере </typeparam>
template<typename T>
class RingBuffer
{
	/// <summary>
	/// Индекс следующего для получения элемента
	/// </summary>
	int _head;

	/// <summary>
	/// Индекс места для добавления элемента
	/// </summary>
	int _tail;

	/// <summary>
	/// Массив элементов
	/// </summary>
	T* _array;

	/// <summary>
	/// Размер буфера
	/// </summary>
	int _bufferSize;

	/// <summary>
	/// Кол-во элементов в буфере
	/// </summary>
	int _count;

	/// <summary>
	/// Коэффициент увеличения
	/// </summary>
	int const _magnificationFactor = 2;

public:
	/// <summary>
	/// Создать экземпляр класса
	/// </summary>
	/// <param name="_length"> Размер буфера </param>
	RingBuffer(int _length);

	/// <summary>
	/// Освободить память
	/// </summary>
	~RingBuffer();

	/// <summary>
	/// Добавить элемент
	/// </summary>
	/// <param name="value"> Элемент </param>
	void Enqueue(T value);

	/// <summary>
	/// Взять элемент
	/// </summary>
	T Dequeue();

	/// <summary>
	/// Возвращает признак пустого буфера
	/// </summary>
	/// <returns> true, если буфер пуст, иначе false </returns>
	bool IsEmpty();

	/// <summary>
	/// Возвращает признак полностью заполненного буфера 
	/// </summary>
	/// <returns> true, если буфер полный, иначе false </returns>
	bool IsFull();

	/// <summary>
	/// Очистить буфер
	/// </summary>
	void Clear();

	/// <summary>
	/// Увеличить вместимость
	/// </summary>
	void IncreaseCapacity();

private:
	/// <summary>
	/// Получить следующий индекс элемента
	/// </summary>
	/// <param name="position"> Следующая позиция элемента </param>
	int NextPosition(int position);
};