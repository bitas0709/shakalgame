#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;

Game::Game() //конструктор, в котором и проихсодит весь игровой процесс
{
	Unit Hero = new Unit();
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
		system("color 07");
		MoveCursor(0, 0);
		MoveCursor(x, y);
		//cout << "^";
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
	//cout << prs;
	if ((prs == 119)||(prs == 230)||(prs == 72)) { //нажатие на кнопку w или ц
		if ((y > 1) && (world[y - 1][x] == ' ')) {
			MoveCursor(x, y);
			cout << world[y][x];
			y -= 1;
			MoveCursor(x, y);
			cout << model[0];
			//cout << "^";
		}
		else {
			MoveCursor(x, y);
			cout << model[0];
		}
	}
	else if ((prs == 97)||(prs == 228)||(prs == 75)) { //нажатие на кнопку a или ф
		if ((x > 1) && (world[y][x - 1] == ' ')) {
			MoveCursor(x, y);
			cout << world[y][x];
			x -= 1;
			MoveCursor(x, y);
			cout << model[1];
			//cout << "<";
		}
		else {
			MoveCursor(x, y);
			cout << model[1];
		}
	}
	else if ((prs == 115)||(prs == 235)||(prs == 80)) { //нажатие на кнопку s или ы
		if ((y < 24) && (world[y + 1][x] == ' ')) {
			MoveCursor(x, y);
			cout << world[y][x];
			y += 1;
			MoveCursor(x, y);
			cout << model[3];
			//cout << "V";
		}
		else {
			MoveCursor(x, y);
			cout << model[3];
		}
	}
	else if ((prs == 100)||(prs == 162)||(prs == 77)) { //нажатие на кнопку d или в
		if ((x < 79) && (world[y][x + 1] == ' ')) {
			MoveCursor(x, y);
			cout << world[y][x];
			x += 1;
			MoveCursor(x, y);
			cout << model[2];
			//cout << ">";
		}
		else {
			MoveCursor(x, y);
			cout << model[2];
		}
	}
}

void Game::Mov() {

}


Game::~Game()
{
}
