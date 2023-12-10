#pragma once
#include <string>

using namespace std;

/// <summary>
/// Ѕазовый класс модели представлени€
/// </summary>
class BaseView
{
protected:
	
	/// <summary>
	/// —оздать экземпл€р класса
	/// </summary>
	BaseView();

	/// <summary>
	/// ¬вести целое число
	/// </summary>
	/// <returns> ÷елое число </returns>
	int InsertIntValue();
};
