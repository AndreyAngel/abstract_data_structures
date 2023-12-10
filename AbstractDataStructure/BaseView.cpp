#include "BaseView.h"
#include "iostream"

using namespace std;

BaseView::BaseView()
{
    setlocale(LC_ALL, "Russian");
}

int BaseView::InsertIntValue()
{
    int value;

    while (true)
    {
        cin >> value;

        if (!cin)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Необходимо ввести целое число!" << endl;
        }

        cout << endl;
        return value;
    }
}
