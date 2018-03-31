#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;

extern HANDLE hStdOut;
extern COORD CursorPos;
extern void MoveCursor(short x, short y);

Game::Game() //�����������, � ������� � ���������� ���� ������� �������
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
		Arena->GenerateFromFile(); //�������� ���� �� ������
		Player = new Hero(15,15); 		//cout << "^";
		system("color 07");
		MoveCursor(x, y);
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
	CONSOLE_CURSOR_INFO structCursorInfo;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
	if ((prs == 119)||(prs == 230)||(prs == 72)) { //������� �� ������ w ��� �
		Player->Move(Player->CorX, Player->CorY - 1, Arena);
	}
	else if ((prs == 97)||(prs == 228)||(prs == 75)) { //������� �� ������ a ��� �
		Player->Move(Player->CorX - 1, Player->CorY, Arena);
	}
	else if ((prs == 115)||(prs == 235)||(prs == 80)) { //������� �� ������ s ��� �
		Player->Move(Player->CorX, Player->CorY + 1, Arena);
	}
	else if ((prs == 100)||(prs == 162)||(prs == 77)) { //������� �� ������ d ��� �
		Player->Move(Player->CorX + 1, Player->CorY, Arena);
	}
}



Game::~Game()
{
}
