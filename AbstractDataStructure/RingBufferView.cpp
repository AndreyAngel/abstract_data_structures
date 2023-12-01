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

    cout << "������� ����������� ���������� ������: ";
    cin >> _size;
    if (!cin)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "���������� ������ ����� ������������� �����!" << endl;
        return;
    }

    if (_size < 0)
    {
        cout << "���������� ������ ����� ������������� �����!" << endl;
        return;
    }

    _ringBuffer = new RingBuffer<int>(_size);

    while (flag)
    {
        cout << "�������� ��� ���������� �������:" << endl;
        cout << "1. ��������� � �������� � �����" << endl
             << "2. ����� ������� �� ������" << endl
             << "3. �������� �����" << endl
             << "4. ����� � ������� ����" << endl;

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
    
    _ringBuffer->Enqueue(value);
    Print();
}

void RingBufferView::Dequeue()
{
    if (_ringBuffer->IsEmpty())
    {
        cout << "��������� ����� ����, ������� ������." << endl << endl;;
        return;
    }

    cout << _ringBuffer->Dequeue() << endl;
    Print();
}

void RingBufferView::Print()
{
    RingBuffer<int>* newBuffer = new RingBuffer<int>(_size);

    cout << "������� �����: ";

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
