#include "StackBasedQueueView.h"
#include "iostream"

using namespace std;

StackBasedQueueView::StackBasedQueueView()
{
	Initialize();
}

void StackBasedQueueView::Initialize()
{
    _queue = new StackBasedQueue<int>(5);

    while (true)
    {
        cout << "Выберите что необходимо сделать:" << endl;
        cout << "1. Добавить элемент в очередь"
            "\n2. Извлечь элемент из очереди"
            "\n3. Очистить очередь"
            "\n4. Выход в главное меню" << endl;

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

void StackBasedQueueView::Enqueue()
{
    cout << "Введите элемент, который необходимо добавить: ";
    //TODO: duplication
    int value = InsertIntValue();
    
    _queue->Enqueue(value);
    _size++;
    Print();
}

void StackBasedQueueView::Dequeue()
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

void StackBasedQueueView::Print()
{
    StackBasedQueue<int>* newQueue = new StackBasedQueue<int>(_size);

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

    delete newQueue;
}
