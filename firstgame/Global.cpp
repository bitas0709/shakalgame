#include "stdafx.h"
#include "Global.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;


Global::Global()
{
	Global::SetWinProp(mwx, mwy);
}

void Global::MoveCursor(short x, short y) { //����������� �������
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

void Global::Window(int mstr, int mchr, char mass[20][15], int background) {
	int done = 0; //����������, ������� ��������� ���������� ������ ���� ���� ���
	short mwxn = (mwx - mchr) / 2; //���������� x, � ������� ������� ��������� ���� (MoveWindowXNew)
	short mwyn = (mwy - mstr) / 2; //���������� y, � ������� ������� ��������� ���� (MoveWindowYNew)
	short mwxc = mwxn + 1; //���������� x, � ������� ������� �������� ������ (MoveWindowXCurrent)
	short mwyc = mwyn + 1; //���������� y, � ������� ������� ��������� ������ (MoveWindowYCurrent) 
	MoveCursor(mwxn, mwyn);
	cout << "+";
	for (int j = 0; j < mchr; j++) {
		cout << "-";
	}
	cout << "+";
	if (done == 0) {
		for (int j = 0; j < mstr; j++) {
			MoveCursor(mwxn, mwyn + 1 + j);
			cout << "|";
			MoveCursor(mwxn + mchr + 1, mwyn + 1 + j);
			cout << "|";
		}
	}
	MoveCursor(mwxn, mwyn + mstr + 1);
	cout << "+";
	for (int j = 0; j < mchr; j++) {
		cout << "-";
	}
	cout << "+";
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
			if (prs == 119) {
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
			else if (prs == 115) {
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
	/*MoveCursor(startx, starty);
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
	}*/

}

Global::~Global()
{
}
