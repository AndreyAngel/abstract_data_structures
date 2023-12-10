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
        cout << "�������� ��� ���������� �������:" << endl;
        cout << "1. �������� ������� � �������"
            "\n2. ������� ������� �� �������"
            "\n3. �������� �������"
            "\n4. ����� � ������� ����" << endl;

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
                cout << "���������� ������ �������� �� 1 �� 4" << endl << endl;
                break;
        }
    }
}

void StackBasedQueueView::Enqueue()
{
    cout << "������� �������, ������� ���������� ��������: ";
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
        cout << "������� ������, ������� ������" << endl;
        return;
    }

    cout << _queue->Dequeue() << endl;
    _size--;
    Print();
}

void StackBasedQueueView::Print()
{
    StackBasedQueue<int>* newQueue = new StackBasedQueue<int>(_size);

    cout << "������� �������: ";

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
