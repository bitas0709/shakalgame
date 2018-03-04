#pragma once
#include "Global.h"
#include <windows.h>
class Global
{
public:
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD CursorPos;
	int x = 0, y = 0; //начальные координаты курсора
	int mwx = 80, mwy = 25; //размеры окна по умолчанию (main window x, main window y)
	void MoveCursor(short x, short y); //функция для перемещения курсора
	void SetWinProp(); //функция для установки параметров консоли (размера и прочего)
	Global();
	~Global();
};

