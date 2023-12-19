#include <iostream>

using namespace std;

/// <summary>
/// Задать целочисленное значение
/// </summary>
/// <returns> Число </returns>
static int InsertIntValue()
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