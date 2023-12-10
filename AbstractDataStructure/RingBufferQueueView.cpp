#include "RingBufferQueueView.h"
#include "iostream"

using namespace std;

RingBufferQueueView::RingBufferQueueView()
{
	Initialize();
}

void RingBufferQueueView::Initialize()
{
    _queue = new RingBufferQueue<int>(5);

    while (true)
    {
        cout << "Выберите что необходимо сделать:" << endl;
        cout << "1. Добавить элемент в очередь"
                "\n2. Извлечь элемент из очереди"
                "\n3. Очистить очередь"
                "\n4. Выход в главное меню" << endl;

        //TODO: duplication
        int choose = InsertIntValue();

        switch (choose)
        {
            case 1:
                Enqueue();
                break;

            case 2:
                Dequeue();
                break;

            case 3:
                _queue->Clear();
                break;
            case 4:
                delete _queue;
                return;

            default:
                cout << "Необходимо ввести значение от 1 до 4" << endl << endl;
                break;
        }
    }
}

void RingBufferQueueView::Enqueue()
{
    cout << "Введите элемент, который необходимо добавить: ";

    //TODO: duplication
    int value = InsertIntValue();

    _queue->Enqueue(value);
    _size++;
    Print();
}

void RingBufferQueueView::Dequeue()
{
    if (_queue->IsEmpty())
    {
        cout << "Очередь пустая, удалять нечего" << endl;
        return;
    }
    
    cout << _queue->Dequeue() << endl;
    _size--;
    Print();
}

void RingBufferQueueView::Print()
{
    RingBufferQueue<int>* newQueue = new RingBufferQueue<int>(_size);

    cout << "Текущая очередь: ";

    while (!_queue->IsEmpty())
    {
        int element = _queue->Dequeue();
        cout << element << ' ';
        newQueue->Enqueue(element);
    }

    cout << endl;

    while (!newQueue->IsEmpty())
    {
        _queue->Enqueue(newQueue->Dequeue());
    }
}
