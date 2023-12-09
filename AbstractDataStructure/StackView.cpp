#include "StackView.h"
#include "iostream"

using namespace std;

StackView::StackView()
{
    Initialize();
}

void StackView::Initialize()
{
    _stack = new Stack<int>(5);

    while (true)
    {
        cout << "�������� ��� ���������� �������:" << endl;
        cout << "1. ��������� ������� � ����" << endl
             << "2. ����� ������� �� �����" << endl
             << "3. �������� ����" << endl
             << "4. ����� � ������� ����" << endl;
        //TODO: duplication
        int choose;
        string result = InsertIntValue(choose);
        if (result != "")
        {
            cout << result;
            continue;
        }

        switch (choose)
        {
            case 1:
                Push();
                break;

            case 2:
                Pop();
                break;

            case 3:
                _stack->Clear();
                break;

            case 4:
                delete _stack;
                return;

            default:
                cout << endl;
                break;
        }
    }
}

void StackView::Push()
{
    cout << "������� ����� ������� ���������� ��������: ";
    //TODO: duplication
    int value;
    string result = InsertIntValue(value);
    if (result != "")
    {
        cout << result;
        return;
    }
    
    _stack->Push(value);
    _size++;
    Print();
}

void StackView::Pop()
{
    if (_stack->IsEmpty())
    {
        cout << "���� ����, ������� ������." << endl;
    }
    else
    {
        cout << _stack->Pop() << endl;
        _size--;
        Print();
    }
}

void StackView::Print()
{
    Stack<int>* newStack = new Stack<int>(_size);

    cout << "������� ����: ";

    while (!_stack->IsEmpty())
    {
        int element = _stack->Pop();
        cout << element << ' ';
        newStack->Push(element);
    }

    cout << endl;
    
    while (!newStack->IsEmpty())
    {
        _stack->Push(newStack->Pop());
    }

    delete newStack;
}
