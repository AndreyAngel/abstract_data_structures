#include <iostream>

using namespace std;

/// <summary>
/// ������ ������������� ��������
/// </summary>
/// <returns> ����� </returns>
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
            cout << "���������� ������ ����� �����!" << endl;
            continue;
        }

        cout << endl;
        return value;
    }
}