#include "stdafx.h"
#include "Game.h"
#include "Menu.h"
#include "Unit.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;

Game::Game() //конструктор, в котором и проихсодит весь игровой процесс
{
	Global::Window(str, chr, butt, 1);
	//Game::wind();
	if (Global::mtrue == true) {
//		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(hStdOut, &structCursorInfo);
		structCursorInfo.bVisible = false;
		SetConsoleCursorInfo(hStdOut, &structCursorInfo);
		//COORD CursorPos;
		MoveCursor(0, 0);
		Game::Generator();
		MoveCursor(0, 0);
		MoveCursor(x, y);
		cout << model[0];
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
//	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
	//COORD CursorPos;
	if (prs == 119) { //нажатие на кнопку w
		if (y > 0) {
			MoveCursor(x, y);
			cout << world[y][x];
			y -= 1;
			MoveCursor(x, y);
			cout << model[0];
		}
	}
	else if (prs == 97) { //нажатие на кнопку a
		if (x > 0) {
			MoveCursor(x, y);
			cout << world[y][x];
			x -= 1;
			MoveCursor(x, y);
			cout << model[0];
		}
	}
	else if (prs == 115) { //гажатие на кнопку s
		if (y < 24) {
			MoveCursor(x, y);
			cout << world[y][x];
			y += 1;
			MoveCursor(x, y);
			cout << model[0];
		}
	}
	else if (prs == 100) { //нажатие на кнопку d
		if (x < 79) {
			MoveCursor(x, y);
			cout << world[y][x];
			x += 1;
			MoveCursor(x, y);
			cout << model[0];
		}
	}
}

void Game::Mov() {

}


Game::~Game()
{
}
