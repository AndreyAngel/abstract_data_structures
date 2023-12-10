#include "RingBufferView.h"
#include "iostream"

using namespace std;

RingBufferView::RingBufferView()
{
    Initialize();
}

void RingBufferView::Initialize()
{
    //TODO: duplication

    cout << "������� ����������� ���������� ������: ";
    _size = InsertIntValue();

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
             << "3. �������� �����" << endl
             << "4. ����� � ������� ����" << endl;

        //TODO: duplication
        int choose = InsertIntValue();

        switch (choose)
        {
            //TODO: RSDN
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

    int value = InsertIntValue();
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
}
