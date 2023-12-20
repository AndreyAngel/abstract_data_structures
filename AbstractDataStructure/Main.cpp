#include <iostream>
#include "StackView.h"
#include "RingBufferView.h"
#include "StackBasedQueueView.h"
#include "RingBufferQueueView.h"

using namespace std;

int main()
{
    IOConsoleHelper* ioHelper = new IOConsoleHelper();

    setlocale(LC_ALL, "Russian");
    while (true)
    {
        cout << "Выберите что необходимо сделать: " << endl;
        cout << "1. Создание стэка" << endl
             << "2. Создание кольцевого буфера" << endl
             << "3. Создание очереди на базе 2 стеков" << endl
             << "4. Создание очереди на базе кольцевого буфера" << endl;

        //TODO: duplication
        int dataStructureChoose = ioHelper->InsertIntValue();

        switch (dataStructureChoose)
        {
            case 1:
            {
                StackView* stackView = new StackView(ioHelper);
            }
            break;

            case 2: 
            {
                RingBufferView* ringView = new RingBufferView(ioHelper);
            }
            break;

            case 3:
            {
                StackBasedQueueView* queue = new StackBasedQueueView(ioHelper);
            }
            break;

            case 4:
            {
                RingBufferQueueView* ringBufferQueueView = new RingBufferQueueView(ioHelper);
            }
            break;

            default:
                cout << "Необходимо ввести значение от 1 до 4" << endl << endl;
                break;
        }
    }
}