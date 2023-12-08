#include "Stack.h"
#include <iostream>

template<typename T>
Stack<T>::Stack()
{
    _capacity = 3;
    _array = new T[3];
    _magnificationFactor = 2;
}

template<typename T>
Stack<T>::Stack(int capacity)
{
    _capacity = capacity;
    _array = new T[capacity];
    _magnificationFactor = 2;
}

template<typename T>
Stack<T>::Stack(int length, int capacity, T* array)
{
    _length = length;
    _capacity = capacity;
	_array = array;
    _magnificationFactor = 2;
}

template<typename T>
Stack<T>::~Stack()
{
    delete[] _array;
    _length = 0;
    _capacity = 0;
    _magnificationFactor = 0;
}

template<typename T>
void Stack<T>::Push(T value)
{
    if (_length == _capacity)
    {
        _capacity *= _magnificationFactor;
        T* newArray = new T[_capacity];

        for (int i = 0; i < _length; i++)
        {
            newArray[i] = _array[i];
        }

        delete[] _array;
        _array = newArray;

        newArray = nullptr;
    }

    _array[_length] = value;
    _length++;
}

template<typename T>
T Stack<T>::Pop()
{
    if (_length == 0)
    {
        throw new _exception();
    }

    T element = _array[_length - 1];
    _array[_length - 1] = NULL;
    _length--;

    return element;
}

template<typename T>
void Stack<T>::Clear()
{
    for (int i = 0; i < _length; i++)
    {
        _array[i] = NULL;
    }
    //delete[] _array;
    _length = 0;
}

template<typename T>
bool Stack<T>::IsEmpty()
{
    return _length == 0;
}