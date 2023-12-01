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

    bool flag = true;
    int choose;

    while (flag)
    {
        cout << "�������� ��� ���������� �������:" << endl;
        cout << "1. ��������� ������� � ����" << endl
             << "2. ����� ������� �� �����" << endl
             << "3. �������� ����" << endl
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
                flag = false;
                break;

            default:
                cout << endl;
                break;
        }
    }
}

void StackView::Push()
{
    cout << "������� ����� ������� ���������� ��������: ";

    int value;

    cin >> value;
    if (!cin)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "���������� ������ ����� �����!" << endl;
    }
    else
    {
        _stack->Push(value);
        Print();
    }
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
        Print();
    }
}

void StackView::Print()
{
    Stack<int>* newStack = new Stack<int>(5);

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
