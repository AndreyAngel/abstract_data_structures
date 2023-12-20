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
    cout << "������� ����������� ���������� ������: ";
    _size = _ioHelper->InsertIntValue();

    if (_size < 0)
    {
        cout << "���������� ������ ����� ������������� �����!" << endl;
        return;
    }

    _ringBuffer = new RingBuffer<int>(_size);

    while (true)
    {
        cout << "�������� ��� ���������� �������:" << endl;
        cout << "1. ��������� � �������� � �����" << endl
             << "2. ����� ������� �� ������" << endl
             << "3. ��������� ������ ������ � 2 ����" << endl
             << "4. �������� �����" << endl
             << "5. ����� � ������� ����" << endl;

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
                cout << "���������� ������ �������� �� 1 �� 4" << endl << endl;
                break;
        }
    }
}

void RingBufferView::Enqueue()
{
    cout << "������� �������, ������� ���������� ��������: ";

    int value = _ioHelper->InsertIntValue();
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
