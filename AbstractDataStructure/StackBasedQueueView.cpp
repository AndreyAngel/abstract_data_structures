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
    bool flag = true;

    while (flag == true)
    {
        cout << "�������� ��� ���������� �������:" << endl;
        cout << "1. �������� ������� � �������"
            "\n2. ������� ������� �� �������"
            "\n3. �������� �������"
            "\n4. ����� � ������� ����" << endl;

        int choose;
        cin >> choose;

        if (!cin)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "���������� ������ ����� �����!" << endl;
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

void StackBasedQueueView::Enqueue()
{
    cout << "������� �������, ������� ���������� ��������: ";

    int value;
    cin >> value;

    if (!cin)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "���������� ������ ����� �����!" << endl;
        return;
    }
    
    _queue->Enqueue(value);
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
    Print();
}

void StackBasedQueueView::Print()
{
    StackBasedQueue<int>* newQueue = new StackBasedQueue<int>(5);

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