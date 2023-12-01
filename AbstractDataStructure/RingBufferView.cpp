#include "RingBufferView.h"
#include "iostream"

using namespace std;

RingBufferView::RingBufferView()
{
    Initialize();
}

void RingBufferView::Initialize()
{
    bool flag = true;
    int choose;

    cout << "Введите размерность кольцевого буфера: ";
    cin >> _size;
    if (!cin)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Необходимо ввести целое положительное число!" << endl;
        return;
    }

    if (_size < 0)
    {
        cout << "Необходимо ввести целое положительное число!" << endl;
        return;
    }

    _ringBuffer = new RingBuffer<int>(_size);

    while (flag)
    {
        cout << "Выберите что необходимо сделать:" << endl;
        cout << "1. Поместить в эелемент в буфер" << endl
             << "2. Взять элемент из буфера" << endl
             << "3. Очистить буфер" << endl
             << "4. Выход в главное меню" << endl;

        cin >> choose;
        if (!cin)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Необходимо ввести целое число!" << endl;
        }
        cout << endl;

        switch (choose)
        {
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
            flag = false;
            break;

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
    cin >> value;

    if (!cin)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Необходимо ввести целое число!" << endl;
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
    //delete newBuffer;
}
