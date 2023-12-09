#include "RingBufferView.h"
#include "iostream"

using namespace std;

RingBufferView::RingBufferView()
{
    Initialize();
}

void RingBufferView::Initialize()
{
    //TODO: duplication
    int choose;

    cout << "Введите размерность кольцевого буфера: ";
    string result = InsertIntValue(_size);
    if (result != "")
    {
        cout << result;
        return;
    }

    if (_size < 0)
    {
        cout << "Необходимо ввести целое положительное число!" << endl;
        return;
    }

    _ringBuffer = new RingBuffer<int>(_size);

    while (true)
    {
        cout << "Выберите что необходимо сделать:" << endl;
        cout << "1. Поместить в эелемент в буфер" << endl
             << "2. Взять элемент из буфера" << endl
             << "3. Очистить буфер" << endl
             << "4. Выход в главное меню" << endl;

        //TODO: duplication
        string result = InsertIntValue(choose);
        if (result != "")
        {
            cout << result;
            continue;
        }

        switch (choose)
        {
            //TODO: RSDN
            case 1:
                Enqueue();
                break;

            case 2:
                Dequeue();
                break;

            case 3:
                _ringBuffer->Clear();
                break;

            case 4:
                delete _ringBuffer;
                return;

            default:
                cout << endl;
                break;
        }
    }
}

void RingBufferView::Enqueue()
{
    cout << "Введите элемент, который необходимо добавить: ";

    int value;
    string result = InsertIntValue(value);
    if (result != "")
    {
        cout << result;
        return;
    }
    
    _ringBuffer->Enqueue(value);
    Print();
}

void RingBufferView::Dequeue()
{
    if (_ringBuffer->IsEmpty())
    {
        cout << "Кольцевой буфер пуст, удалять нечего." << endl << endl;;
        return;
    }

    cout << _ringBuffer->Dequeue() << endl;
    Print();
}

void RingBufferView::Print()
{
    RingBuffer<int>* newBuffer = new RingBuffer<int>(_size);

    cout << "Текущий буфер: ";

    while (!_ringBuffer->IsEmpty())
    {
        int element = _ringBuffer->Dequeue();
        cout << element << ' ';
        newBuffer->Enqueue(element);
    }

    cout << endl;

    _ringBuffer = newBuffer;
}
