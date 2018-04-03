﻿#include "stdafx.h"
#include "Global.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;

extern HANDLE hStdOut;
extern COORD CursorPos;
extern void MoveCursor(short x, short y);

Global::Global()
{
	static const TCHAR* title = TEXT("shakalgame.v0.00002");
	SetConsoleTitle(title);
	COORD crd = { 80, 26 };
	SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
	SetConsoleWindowInfo(hStdOut, true, &src);
	SetConsoleScreenBufferSize(hStdOut, crd);
}



void Global::Window(int mstr, int mchr, char mass[20][14], int background) {
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = false;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
	int done = 0; //переменная, которая позволяет отрисовать стенки окна один раз
	short mwxn = (mwx - mchr) / 2; //координата x, с которой начнётся отрисовка окна (MoveWindowXNew)
	short mwyn = (mwy - mstr) / 2; //координата y, с которой начнётся отрисовка окна (MoveWindowYNew)
	short mwxc = mwxn + 1; //координата x, с которой начнётся отрисока кнопок (MoveWindowXCurrent)
	short mwyc = mwyn + 1; //координата y, с которой начнётся отрисовка кнопок (MoveWindowYCurrent) 
	for (int m = 0; m < mstr / 2 + 1; m++) {
		for (int i = 0; i < mchr / 2 - 1; i++) {
			SetConsoleTextAttribute(hStdOut, (WORD)(background << 5));
			MoveCursor(mwx / 2 - 2 - i, mwy / 2 - m);
			cout << "+";
			for (int j = 0; j < i; j++) {
				cout << "-";
			}
			MoveCursor(mwx / 2 - 2 + i, mwy / 2 - m);
			for (int j = 0; j < i; j++) {
				cout << "-";
			}
			cout << "+";
			MoveCursor(mwx / 2 - 2 - i, mwy / 2 + 1 + m);
			cout << "+";
			for (int j = 0; j < i; j++) {
				cout << "-";
			}
			MoveCursor(mwx / 2 - 2 + i, mwy / 2 + 1 + m);
			for (int j = 0; j < i; j++) {
				cout << "-";
			}
			cout << "+";
			for (int u = 0; u < m; u++) {
				MoveCursor(mwx / 2 - 2 - i, mwy / 2 - m + 1);
				cout << "|";
				for (int j = 0; j < i * 2 + 4; j++) {
					cout << " ";
				}
				cout << "|";
				MoveCursor(mwx / 2 - 2 - i, mwy / 2 + m);
				cout << "|";
				for (int j = 0; j < i * 2 + 4; j++) {
					cout << " ";
				}
				cout << "|";
			}
			if (m == 0) {
				Sleep(100);
			}
		}
		Sleep(100);
	}
	//Sleep(20000);
	for (int i = 0; i < mstr; i++) {
		MoveCursor(mwxc + 2, mwyc + i);
		cout << mass[i];
	}
	int mn = 0;
	MoveCursor(mwxc, mwyc);
	cout << "*";
	MoveCursor(mwxc + mchr - 1, mwyc);
	cout << "*";
	while (mn == 0) {
		if (_kbhit() == 0) {
			Sleep(100);
		}
		else {
			prs = _getch();
			if ((prs == 119)||(prs == 230)||(prs == 72)) {
				if (mwyc > mwyn + 1) {
					MoveCursor(mwxc, mwyc);
					cout << " ";
					MoveCursor(mwxc + mchr - 1, mwyc);
					cout << " ";
					ret -= 1;
					mwyc -= 1;
					MoveCursor(mwxc, mwyc);
					cout << "*";
					MoveCursor(mwxc + mchr - 1, mwyc);
					cout << "*";
				}
			}
			else if ((prs == 115)||(prs == 235)||(prs == 80)) {
				if (mwyc < mwyn + mstr) {
					MoveCursor(mwxc, mwyc);
					cout << " ";
					MoveCursor(mwxc + mchr - 1, mwyc);
					cout << " ";
					ret += 1;
					mwyc += 1;
					MoveCursor(mwxc, mwyc);
					cout << "*";
					MoveCursor(mwxc + mchr - 1, mwyc);
					cout << "*";
				}
			}
			else if (prs == 13) { //Нажатие на кнопку Enter
				if (ret == 0) { //Новая игра
					mtrue = true;
					mn = 1;
					//cout << "haha, lol";
				}
				else if (ret == 1) { //Опции
					//cout << "hehmda";		 /*Опции. Пока в разработке*/
				}
				else if (ret == 2) { //Об игре
					//cout << "nope";				 /*Об игре. Пока в разработке*/
				}
				else if (ret == 3) { //Выход из игры
					//cout << "hehehe";
					mn = 1;
				}
			}
		}
	}
}

Global::~Global()
{
}
