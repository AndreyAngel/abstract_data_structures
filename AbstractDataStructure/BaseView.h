#pragma once
#include <string>

using namespace std;

/// <summary>
/// ������� ����� ������ �������������
/// </summary>
class BaseView
{
protected:
	
	/// <summary>
	/// ������� ��������� ������
	/// </summary>
	BaseView();

	/// <summary>
	/// ������ ����� �����
	/// </summary>
	/// <returns> ������ ������ ��� ������ </returns>
	string InsertIntValue(int& value);
};
