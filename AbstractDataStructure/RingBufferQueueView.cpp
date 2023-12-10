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
        cout << "�������� ��� ���������� �������:" << endl;
        cout << "1. �������� ������� � �������"
                "\n2. ������� ������� �� �������"
                "\n3. �������� �������"
                "\n4. ����� � ������� ����" << endl;

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
                cout << "���������� ������ �������� �� 1 �� 4" << endl << endl;
                break;
        }
    }
}

void RingBufferQueueView::Enqueue()
{
    cout << "������� �������, ������� ���������� ��������: ";

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
        cout << "������� ������, ������� ������" << endl;
        return;
    }
    
    cout << _queue->Dequeue() << endl;
    _size--;
    Print();
}

void RingBufferQueueView::Print()
{
    RingBufferQueue<int>* newQueue = new RingBufferQueue<int>(_size);

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
}
