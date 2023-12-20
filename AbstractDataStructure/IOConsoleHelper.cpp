#include <iostream>
#include "IOConsoleHelper.h"

using namespace std;

int IOConsoleHelper::InsertIntValue()
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
            continue;
        }

        cout << endl;
        return value;
    }
}

string IOConsoleHelper::GetLine()
{
    string inputString;
    getline(cin, inputString);

    if (inputString.empty())
    {
        getline(cin, inputString);
    }

    return inputString;
}