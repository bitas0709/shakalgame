﻿#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;

extern HANDLE hStdOut;
extern COORD CursorPos;
extern void MoveCursor(short x, short y);

Game::Game() //конструктор, в котором и проихсодит весь игровой процесс
{
	Global::Window(str, chr, butt, 1);

	//Game::wind();
	if (Global::mtrue == true) {
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(hStdOut, &structCursorInfo);
		structCursorInfo.bVisible = false;
		SetConsoleCursorInfo(hStdOut, &structCursorInfo);
		MoveCursor(0, 0);
		Arena = new World;
		Arena->GenerateFromFile(); //Создание мира на экране
		Player = new Hero(15,15); 		//cout << "^";
		system("color 07");
		MoveCursor(x, y);
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
	CONSOLE_CURSOR_INFO structCursorInfo;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
	if ((prs == 119)||(prs == 230)||(prs == 72)) { //нажатие на кнопку w или ц
		Player->Move(Player->CorX, Player->CorY - 1, Arena);
	}
	else if ((prs == 97)||(prs == 228)||(prs == 75)) { //нажатие на кнопку a или ф
		Player->Move(Player->CorX - 1, Player->CorY, Arena);
	}
	else if ((prs == 115)||(prs == 235)||(prs == 80)) { //нажатие на кнопку s или ы
		Player->Move(Player->CorX, Player->CorY + 1, Arena);
	}
	else if ((prs == 100)||(prs == 162)||(prs == 77)) { //нажатие на кнопку d или в
		Player->Move(Player->CorX + 1, Player->CorY, Arena);
	}
}



Game::~Game()
{
}
