#include "stdafx.h"
#include "Global.h"
#include <windows.h>
using namespace std;


Global::Global()
{
}

void Global::MoveCursor(int x, int y) { //перемещение курсора
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD CursorPos = { x, y };
	SetConsoleCursorPosition(hStdOut, CursorPos);
}

void Global::setwinprop() {

}

Global::~Global()
{
}
