#pragma once
#pragma once
#include <string>

/// <summary>
/// ��������� ����� ��� ������ � ��������
/// </summary>
class IOConsoleHelper
{

public:

	/// <summary>
	/// ������ ������������� ��������
	/// </summary>
	/// <returns> ����� </returns>
	static int InsertIntValue();

	/// <summary>
	/// ������� �������� ������ � �������
	/// </summary>
	/// <returns> ������ </returns>
	static std::string GetLine();
};