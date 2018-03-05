#include "stdafx.h"
#include "Menu.h"
#include <windows.h>
#include <conio.h>
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

	MoveCursor(wx, wy);
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
	key();
}

void Menu::key() {
	bool mn = 0; //переменная, отвечающая за выполнение цикла while
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = false;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
	COORD CursorPos;
	MoveCursor(mx, my);
	cout << "*";
	MoveCursor(mx + 9, my);
	cout << "*";
	for (int i = 0; i < str; i++) {
		MoveCursor(mx + 1, my + i);
		cout << butt[i];
	}
	while (mn == 0) {
		if (_kbhit() == 0) {
			Sleep(100);
		}
		else {
			prs = _getch();
			if (prs == 119) {
				if (my > 10) {
					MoveCursor(mx, my);
					cout << " ";
					MoveCursor(mx + 9, my);
					cout << " ";
					my -= 1;
					MoveCursor(mx, my);
					cout << "*";
					MoveCursor(mx + 9, my);
					cout << "*";
				}
			}
			else if (prs == 115) {
				if (my < 13) {
					MoveCursor(mx, my);
					cout << " ";
					MoveCursor(mx + 9, my);
					cout << " ";
					my += 1;
					MoveCursor(mx, my);
					cout << "*";
					MoveCursor(mx + 9, my);
					cout << "*";
				}
			}
			else if (prs == 13) { //Нажатие на кнопку Enter
				if (my == 10) { //Новая игра
					mtrue = true;
					mn = 1;
				}
				else if (my == 11) { //Опции
					/*Опции. Пока в разработке*/
				}
				else if (my == 12) { //Об игре
					/*Об игре. Пока в разработке*/
				}
				else if (my == 13) { //Выход из игры
					mn = 1;
				}
			}
		}
	}
}

void Menu::about() {

}

Menu::Menu()
{
	//wind();
}


Menu::~Menu()
{
}
