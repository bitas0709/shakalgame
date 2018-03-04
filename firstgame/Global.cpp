#include "stdafx.h"
#include "Global.h"
#include <windows.h>
using namespace std;


Global::Global()
{
	Global::setwinprop();
}

void Global::MoveCursor(int x, int y) { //перемещение курсора
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD CursorPos = { x, y };
	SetConsoleCursorPosition(hStdOut, CursorPos);
}

void Global::setwinprop() {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	static const TCHAR* title = TEXT("shakalgame.v0.00001");
	SetConsoleTitle(title);
	COORD crd = { 80, 25 };
	SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
	SetConsoleWindowInfo(hStdOut, true, &src);
	SetConsoleScreenBufferSize(hStdOut, crd);
}

Global::~Global()
{
}
