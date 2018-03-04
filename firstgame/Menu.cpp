#include "stdafx.h"
#include "Menu.h"
#include <windows.h>
#include <iostream>
using namespace std;


void Menu::wind()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = false;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
	COORD CursorPos;
	CursorPos = {(80-chr-4)/2,(25-str-2)/2};
	SetConsoleCursorPosition(hStdOut, CursorPos);
	cout << "+";
	for (int i = 0; i < chr+2; i++) {
		cout << "-";
	}
	cout << "+";
	CursorPos = { (80 - chr - 4) / 2,(25 - str - 2) / 2 + 1};
	SetConsoleCursorPosition(hStdOut, CursorPos);
	for (short i = 0; i < str; i++) {
		cout << "|";
		for (int j = 0; j < chr + 2; j++) {
			cout << " ";
		}
		cout << "|";
		CursorPos = { wx, wy + 2 + i};
		SetConsoleCursorPosition(hStdOut, CursorPos);
	}
	CursorPos = { (80 - chr - 4) / 2,(25 - str - 2) / 2 + str + 1};
	SetConsoleCursorPosition(hStdOut, CursorPos);
	cout << "+";
	for (int i = 0; i < chr + 2; i++) {
		cout << "-";
	}
	cout << "+";
}

void Menu::key() {

}

void Menu::about() {

}

Menu::Menu()
{
	wind();
}


Menu::~Menu()
{
}
