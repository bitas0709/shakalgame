#pragma once
#include "Global.h"
#include <windows.h>
class Global
{
public:
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD CursorPos;
	bool mtrue = false; //переменная, отвечающая за переход в игру
	int x = 0, y = 0; //начальные координаты курсора
	short mwx = 80, mwy = 25; //размеры окна по умолчанию (main window x, main window y)
	void MoveCursor(short x, short y); //функция для перемещения курсора
	void SetWinProp(short mwx, short mwy); //функция для установки параметров консоли (размера и прочего)
	void Window(int mstr, int mchr, char mass[20][30] , int background);
	Global();
	~Global();
};

