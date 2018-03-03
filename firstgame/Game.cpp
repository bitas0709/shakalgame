#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;


Game::Game() //конструктор, в котором и проихсодит весь игровой процесс
{
	Game::Generator();
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = false;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
	COORD CursorPos;
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
			//cout << prs << endl;
			Game::Control(x, y, prs); //вызов функции для изменения положения гг
			Sleep(step);
		}
	}
	/*я буду удивлён, если всё-таки однажды я доделаю этот код до полностью рабочей игры*/
}

void Game::Control(int &x, int &y, int prs) { //x и y - получение текущих координат
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
	COORD CursorPos;
	if (prs == 119) {
		if (y > 0) {
			CursorPos.X = x;
			CursorPos.Y = y;
			SetConsoleCursorPosition(hStdOut, CursorPos);
			cout << world[y][x];
			y -= 1;
			CursorPos.X = x;
			CursorPos.Y = y;
			SetConsoleCursorPosition(hStdOut, CursorPos);
			cout << "%";
		}
	}
	else if (prs == 97) {
		if (x > 0) {
			CursorPos.X = x;
			CursorPos.Y = y;
			SetConsoleCursorPosition(hStdOut, CursorPos);
			cout << world[y][x];
			x -= 1;
			CursorPos.X = x;
			CursorPos.Y = y;
			SetConsoleCursorPosition(hStdOut, CursorPos);
			cout << "%";
		}
	}
	else if (prs == 115) {
		if (y < 25) {
			CursorPos.X = x;
			CursorPos.Y = y;
			SetConsoleCursorPosition(hStdOut, CursorPos);
			cout << world[y][x];
			y += 1;
			CursorPos.X = x;
			CursorPos.Y = y;
			SetConsoleCursorPosition(hStdOut, CursorPos);
			cout << "%";
		}
	}
	else if (prs == 100) {
		if (x < 79) {
			CursorPos.X = x;
			CursorPos.Y = y;
			SetConsoleCursorPosition(hStdOut, CursorPos);
			cout << world[y][x];
			x += 1;
			CursorPos.X = x;
			CursorPos.Y = y;
			SetConsoleCursorPosition(hStdOut, CursorPos);
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

}

void Game::Mov() {

}

Game::~Game()
{
}
