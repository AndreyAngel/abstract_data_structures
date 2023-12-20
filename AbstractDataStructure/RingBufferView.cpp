#include "RingBufferView.h"
#include "iostream"

using namespace std;

RingBufferView::RingBufferView(IOConsoleHelper* ioHelper)
{
    _ioHelper = ioHelper;
    Initialize();
}

void RingBufferView::Initialize()
{
    cout << "Введите размерность кольцевого буфера: ";
    _size = _ioHelper->InsertIntValue();

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
             << "3. Увеличить размер буфера в 2 раза" << endl
             << "4. Очистить буфер" << endl
             << "5. Выход в главное меню" << endl;

        int choose = _ioHelper->InsertIntValue();

        switch (choose)
        {
            case 1:
                Enqueue();
                break;

            case 2:
                Dequeue();
                break;

            case 3:
                _ringBuffer->IncreaseCapacity();
                _size *= 2;
                Print();
                break;

            case 4:
                _ringBuffer->Clear();
                Print();
                break;

            case 5:
                delete _ringBuffer;
                return;

            default:
                cout << "Необходимо ввести значение от 1 до 4" << endl << endl;
                break;
        }
    }
}

void RingBufferView::Enqueue()
{
    cout << "Введите элемент, который необходимо добавить: ";

    int value = _ioHelper->InsertIntValue();
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

    for (int i = 0; i < _size; i++)
    {
        if (!_ringBuffer->IsEmpty())
        {
            int element = _ringBuffer->Dequeue();
            cout << element << ' ';
            newBuffer->Enqueue(element);
        }
        else
        {
            cout << '.' << ' ';
        }
    }

    cout << endl;

    _ringBuffer = newBuffer;
}
