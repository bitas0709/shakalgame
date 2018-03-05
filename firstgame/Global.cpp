#include "stdafx.h"
#include "Global.h"
#include <windows.h>
#include <iostream>
using namespace std;


Global::Global()
{
	Global::SetWinProp(mwx, mwy);
}

void Global::MoveCursor(short x, short y) { //перемещение курсора
	CursorPos = { x, y };
	SetConsoleCursorPosition(hStdOut, CursorPos);
}

void Global::SetWinProp(short mwx, short mwy) {
	static const TCHAR* title = TEXT("shakalgame.v0.00001");
	SetConsoleTitle(title);
	COORD crd = { mwx, mwy };
	SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
	SetConsoleWindowInfo(hStdOut, true, &src);
	SetConsoleScreenBufferSize(hStdOut, crd);
}

void Global::Window(int startx, int starty, int length, int height, int background) {
	int done = 0; //переменная, которая позволяет отрисовать стенки окна один раз
	MoveCursor(startx, starty);
	for (int i = 0; i < 2; i++) {
		cout << "+";
		for (int j = 0; j < length - 2; j++) {
			cout << "-";
		}
		cout << "+";
		if (done == 0) {
			for (int j = 0; j < height - 2; j++) {
				MoveCursor(startx, starty + 1 + i);
				cout << "|";
				MoveCursor(startx + length - 1, starty + 1 + i);
				cout << "|";
			}
		}
	}

}

Global::~Global()
{
}
