#include "stdafx.h"
#include "Global.h"
#include <windows.h>
using namespace std;


Global::Global()
{
	Global::SetWinProp();
}

void Global::MoveCursor(short x, short y) { //перемещение курсора
	CursorPos = { x, y };
	SetConsoleCursorPosition(hStdOut, CursorPos);
}

void Global::SetWinProp() {
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
