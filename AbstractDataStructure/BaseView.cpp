#include "BaseView.h"
#include "iostream"

using namespace std;

BaseView::BaseView()
{
    setlocale(LC_ALL, "Russian");
}

string BaseView::InsertIntValue(int& value)
{
    cin >> value;

    if (!cin)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return "Необходимо ввести целое число!";
    }
    cout << endl;

    return "";
}
