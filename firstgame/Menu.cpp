#include "stdafx.h"
#include "Menu.h"
#include <windows.h>
#include <iostream>
using namespace std;


void Menu::wind()
{
	//Шайтан коробка для того чтобы сделать курсор невидимым, Здесь всё надо!!!
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = false;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);
	//Конец шайтан коробки

	MoveCursor((80 - chr - 4) / 2, (25 - str - 2) / 2);
	cout << "+";
	for (int i = 0; i < chr+2; i++) {
		cout << "-";
	}
	cout << "+";
	MoveCursor((80 - chr - 4) / 2, (25 - str - 2) / 2 + 1);
	for (short i = 0; i < str; i++) {
		cout << "|";
		for (int j = 0; j < chr + 2; j++) {
			cout << " ";
		}
		cout << "|";
		MoveCursor(wx, wy + 2 + i);
	}
	MoveCursor((80 - chr - 4) / 2, (25 - str - 2) / 2 + str + 1);
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
