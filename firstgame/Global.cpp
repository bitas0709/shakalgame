#include "stdafx.h"
#include "Global.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;

Global::Global()
{
	static const TCHAR* title = TEXT("shakalgame.v0.00002");
	SetConsoleTitle(title);
	COORD crd = { 80, 26 };
	SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
	SetConsoleWindowInfo(hStdOut, true, &src);
	SetConsoleScreenBufferSize(hStdOut, crd);
}

void Global::MoveCursor(short x, short y) { //����������� �������
	CursorPos = { x, y };
	SetConsoleCursorPosition(hStdOut, CursorPos);
}

void Global::Window(int mstr, int mchr, char mass[20][14], int background) {
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = false;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
	int done = 0; //����������, ������� ��������� ���������� ������ ���� ���� ���
	short mwxn = (mwx - mchr) / 2; //���������� x, � ������� ������� ��������� ���� (MoveWindowXNew)
	short mwyn = (mwy - mstr) / 2; //���������� y, � ������� ������� ��������� ���� (MoveWindowYNew)
	short mwxc = mwxn + 1; //���������� x, � ������� ������� �������� ������ (MoveWindowXCurrent)
	short mwyc = mwyn + 1; //���������� y, � ������� ������� ��������� ������ (MoveWindowYCurrent) 
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
			else if (prs == 13) { //������� �� ������ Enter
				if (ret == 0) { //����� ����
					mtrue = true;
					mn = 1;
					//cout << "haha, lol";
				}
				else if (ret == 1) { //�����
					//cout << "hehmda";		 /*�����. ���� � ����������*/
				}
				else if (ret == 2) { //�� ����
					//cout << "nope";				 /*�� ����. ���� � ����������*/
				}
				else if (ret == 3) { //����� �� ����
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

//Unit::Unit()
//{
//
//}
//
//
//Unit::~Unit()
//{
//}
//
//void Unit::Mov(int NewX, int NewY)
//{
//
//}
