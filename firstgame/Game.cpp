#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include "Hero.h"
using namespace std;

Game::Game() //�����������, � ������� � ���������� ���� ������� �������
{
	Hero Player(15,15);
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
	//cout << prs;
	if ((prs == 119)||(prs == 230)||(prs == 72)) { //������� �� ������ w ��� �
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
	else if ((prs == 97)||(prs == 228)||(prs == 75)) { //������� �� ������ a ��� �
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
	else if ((prs == 115)||(prs == 235)||(prs == 80)) { //������� �� ������ s ��� �
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
	else if ((prs == 100)||(prs == 162)||(prs == 77)) { //������� �� ������ d ��� �
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
