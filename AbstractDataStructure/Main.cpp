#include <iostream>
#include "StackView.h"
#include "RingBufferView.h"
#include "StackBasedQueueView.h"
#include "RingBufferQueueView.h"
#include "IOConsoleHelper.cpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    while (true)
    {
        cout << "Выберите что необходимо сделать: " << endl;
        cout << "1. Создание стэка" << endl
             << "2. Создание кольцевого буфера" << endl
             << "3. Создание очереди на базе 2 стеков" << endl
             << "4. Создание очереди на базе кольцевого буфера" << endl;

        //TODO: duplication
        int dataStructureChoose = InsertIntValue();

        switch (dataStructureChoose)
        {
            case 1:
            {
                StackView* stackView = new StackView();
            }
            break;

            case 2: 
            {
                RingBufferView* ringView = new RingBufferView();
            }
            break;

            case 3:
            {
                StackBasedQueueView* queue = new StackBasedQueueView();
            }
            break;

            case 4:
            {
                RingBufferQueueView* ringBufferQueueView = new RingBufferQueueView();
            }
            break;

            default:
                cout << "Необходимо ввести значение от 1 до 4" << endl << endl;
                break;
        }
    }
}