#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;


Game::Game() //конструктор, в котором и проихсодит весь игровой процесс
{
	Game::Menu();
	if (mtrue == true) {
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(hStdOut, &structCursorInfo);
		structCursorInfo.bVisible = false;
		SetConsoleCursorInfo(hStdOut, &structCursorInfo);
		COORD CursorPos;
		CursorPos.X = 0;
		CursorPos.Y = 0;
		SetConsoleCursorPosition(hStdOut, CursorPos);
		Game::Generator();
		CursorPos.X = 0;
		CursorPos.Y = 0;
		SetConsoleCursorPosition(hStdOut, CursorPos);
		CursorPos.X = x;
		CursorPos.Y = y;
		SetConsoleCursorPosition(hStdOut, CursorPos);
		cout << "%";
		int wh = 0; //переменная, отвечающая за выход из цикла. 1 закрывает цикл while
		while (wh == 0) {
			if (_kbhit() == 0) {
				Sleep(step);
			}
			else {
				prs = _getch(); /*w - 119, a - 97, s - 115, d - 100 . Если я вдруг забуду, что это, то это коды клавиш, полученных от  функции _getch()
								почему не стрелочки? Они дают какой-то мусор помимо самих клавиш. Если получится разобраться с этим мусором, то нужно будет добавить
								стрелочки как кнопки управления*/
				Game::Control(x, y, prs); //вызов функции для изменения положения гг
				Sleep(step);
			}
		}
	}
	/*я буду удивлён, если всё-таки однажды я доделаю этот код до полностью рабочей игры*/
}

void Game::Control(int &x, int &y, int prs) { //x и y - получение текущих координат
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
	COORD CursorPos;
	if (prs == 119) { //нажатие на кнопку w
		if (y > 0) {
			MCursor(x, y);
			cout << world[y][x];
			y -= 1;
			MCursor(x, y);
			cout << "%";
		}
	}
	else if (prs == 97) { //нажатие на кнопку a
		if (x > 0) {
			MCursor(x, y);
			cout << world[y][x];
			x -= 1;
			MCursor(x, y);
			cout << "%";
		}
	}
	else if (prs == 115) { //гажатие на кнопку s
		if (y < 25) {
			MCursor(x, y);
			cout << world[y][x];
			y += 1;
			MCursor(x, y);
			cout << "%";
		}
	}
	else if (prs == 100) { //нажатие на кнопку d
		if (x < 79) {
			MCursor(x, y);
			cout << world[y][x];
			x += 1;
			MCursor(x, y);
			cout << "%";
		}
	}
}

void Game::Generator() {
	ifstream wrld("world.txt");
	for (int i = 0; i < 25; i++) {
		wrld.getline(world[i], 81); //костыль, так как чтение последнего символа из файла не происходило
		cout << world[i];
	}
	wrld.close();
}

void Game::Menu() {
	system("cls");
	bool mn = 0; //переменная, отвечающая за выполнение цикла while
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = false;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
	COORD CursorPos;
	CursorPos.X = 34;
	CursorPos.Y = 8;
	SetConsoleCursorPosition(hStdOut, CursorPos);
	cout << "+----------+" << endl;
	CursorPos.X = 34;
	CursorPos.Y = 9;
	SetConsoleCursorPosition(hStdOut, CursorPos);
	cout << "|          |" << endl;
	CursorPos.X = 34;
	CursorPos.Y = 10;
	SetConsoleCursorPosition(hStdOut, CursorPos);
	cout << "| New Game |" << endl;
	CursorPos.X = 34;
	CursorPos.Y = 11;
	SetConsoleCursorPosition(hStdOut, CursorPos);
	cout << "| Options  |" << endl;
	CursorPos.X = 34;
	CursorPos.Y = 12;
	SetConsoleCursorPosition(hStdOut, CursorPos);
	cout << "| About    |" << endl;
	CursorPos.X = 34;
	CursorPos.Y = 13;
	SetConsoleCursorPosition(hStdOut, CursorPos);
	cout << "| Exit     |" << endl;
	CursorPos.X = 34;
	CursorPos.Y = 14;
	SetConsoleCursorPosition(hStdOut, CursorPos);
	cout << "|          |" << endl;
	CursorPos.X = 34;
	CursorPos.Y = 15;
	SetConsoleCursorPosition(hStdOut, CursorPos);
	cout << "+----------+" << endl;
	CursorPos.X = mx;
	CursorPos.Y = my;
	SetConsoleCursorPosition(hStdOut, CursorPos);
	cout << "*";
	CursorPos.X = mx + 9;
	SetConsoleCursorPosition(hStdOut, CursorPos);
	cout << "*";
	while (mn == 0) {
		if (_kbhit() == 0) {
			Sleep(100);
		}
		else {
			prs = _getch();
			if (prs == 119) {
				if (my > 10) {
					CursorPos.X = mx;
					CursorPos.Y = my;
					SetConsoleCursorPosition(hStdOut, CursorPos);
					cout << " ";
					CursorPos.X = mx + 9;
					SetConsoleCursorPosition(hStdOut, CursorPos);
					cout << " ";
					my -= 1;
					CursorPos.X = mx;
					CursorPos.Y = my;
					SetConsoleCursorPosition(hStdOut, CursorPos);
					cout << "*";
					CursorPos.X = mx + 9;
					SetConsoleCursorPosition(hStdOut, CursorPos);
					cout << "*";
				}
			}
			else if (prs == 115) {
				if (my < 13) {
					CursorPos.X = mx;
					CursorPos.Y = my;
					SetConsoleCursorPosition(hStdOut, CursorPos);
					cout << " ";
					CursorPos.X = mx + 9;
					SetConsoleCursorPosition(hStdOut, CursorPos);
					cout << " ";
					my += 1;
					CursorPos.X = mx;
					CursorPos.Y = my;
					SetConsoleCursorPosition(hStdOut, CursorPos);
					cout << "*";
					CursorPos.X = mx + 9;
					SetConsoleCursorPosition(hStdOut, CursorPos);
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

void Game::Mov() {

}

void Game::MCursor(int &x, int &y) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	COORD CursorPos;
	CursorPos.X = x;
	CursorPos.Y = y;
	SetConsoleCursorPosition(hStdOut, CursorPos);
}

Game::~Game()
{
}
