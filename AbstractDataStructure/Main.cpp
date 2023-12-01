#include <iostream>

#include "StackView.h"
#include "RingBufferView.h"
#include "StackBasedQueueView.h"
#include "RingBufferQueueView.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    while (true)
    {
        cout << "Выберите что необходимо сделать: " << endl;
        cout << "1. Создание стэка"
                "\n2. Создание кольцевого буфера"
                "\n3. Создание \"очереди\" на базе 2 стеков"
                "\n4. Создание \"очереди\" на базе кольцевого буфера" << endl;

        int dataStructureChoose;
        cin >> dataStructureChoose;
        if (!cin)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Необходимо ввести целое число!" << endl;
        }
        cout << endl;

        bool flag = true;
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
                cout << endl;
                break;
        }
    }
}