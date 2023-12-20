#pragma once
#pragma once
#include <string>

/// <summary>
/// Сервисный класс для работы с консолью
/// </summary>
class IOConsoleHelper
{

public:

	/// <summary>
	/// Задать целочисленное значение
	/// </summary>
	/// <returns> Число </returns>
	static int InsertIntValue();

	/// <summary>
	/// Считать значание строки с консоли
	/// </summary>
	/// <returns> Строка </returns>
	static std::string GetLine();
};