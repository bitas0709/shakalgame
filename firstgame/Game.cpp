#include "stdafx.h"
#include "Game.h"
#include "Menu.h"
#include "Unit.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;

Game::Game() //�����������, � ������� � ���������� ���� ������� �������
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
		int wh = 0; //����������, ���������� �� ����� �� �����. 1 ��������� ���� while
		while (wh == 0) {
			if (_kbhit() == 0) {
				Sleep(step);
			}
			else {
				prs = _getch(); /*w - 119, a - 97, s - 115, d - 100 . ���� � ����� ������, ��� ���, �� ��� ���� ������, ���������� ��  ������� _getch()
								������ �� ���������? ��� ���� �����-�� ����� ������ ����� ������. ���� ��������� ����������� � ���� �������, �� ����� ����� ��������
								��������� ��� ������ ����������*/
				Game::Control(x, y, prs); //����� ������� ��� ��������� ��������� ��
				Sleep(step);
			}
		}
	}
	/*� ���� ������, ���� ��-���� ������� � ������� ���� ��� �� ��������� ������� ����*/
}

void Game::Control(int &x, int &y, int prs) { //x � y - ��������� ������� ���������
//	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
	//COORD CursorPos;
	if (prs == 119) { //������� �� ������ w
		if (y > 0) {
			MoveCursor(x, y);
			cout << world[y][x];
			y -= 1;
			MoveCursor(x, y);
			cout << model[0];
		}
	}
	else if (prs == 97) { //������� �� ������ a
		if (x > 0) {
			MoveCursor(x, y);
			cout << world[y][x];
			x -= 1;
			MoveCursor(x, y);
			cout << model[0];
		}
	}
	else if (prs == 115) { //������� �� ������ s
		if (y < 24) {
			MoveCursor(x, y);
			cout << world[y][x];
			y += 1;
			MoveCursor(x, y);
			cout << model[0];
		}
	}
	else if (prs == 100) { //������� �� ������ d
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
