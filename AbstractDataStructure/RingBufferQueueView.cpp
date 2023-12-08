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

    bool flag = true;

    while (flag)
    {
        cout << "Выберите что необходимо сделать:" << endl;
        cout << "1. Добавить элемент в очередь"
            "\n2. Извлечь элемент из очереди"
            "\n3. Очистить очередь"
            "\n4. Выход в главное меню" << endl;

        int choose;
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
                _queue->Clear();
                break;
            case 4:
                delete _queue;
                flag = false;
                break;

            default:
                cout << endl;
                break;
        }
    }
}

void RingBufferQueueView::Enqueue()
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
    RingBufferQueue<int>* newQueue = new RingBufferQueue<int>(_size + 1);

    cout << "Текущая очередь: ";

    while (!_queue->IsEmpty())
    {
        int element = _queue->Dequeue();
        cout << element << ' ';
        newQueue->Enqueue(element);
    }

    cout << endl;

    //delete _queue;
    //_queue = newQueue;

    while (!newQueue->IsEmpty())
    {
        _queue->Enqueue(newQueue->Dequeue());
    }
}
