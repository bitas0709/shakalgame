#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;


Game::Game() //�����������, � ������� � ���������� ���� ������� �������
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
	int wh = 0; //����������, ���������� �� ����� �� �����. 1 ��������� ���� while
	while (wh == 0) {
		if (_kbhit() == 0) {
			Sleep(step);
		}
		else {
			prs = _getch(); /*w - 119, a - 97, s - 115, d - 100 . ���� � ����� ������, ��� ���, �� ��� ���� ������, ���������� ��  ������� _getch()
							������ �� ���������? ��� ���� �����-�� ����� ������ ����� ������. ���� ��������� ����������� � ���� �������, �� ����� ����� ��������
							��������� ��� ������ ����������*/
			//cout << prs << endl;
			Game::Control(x, y, prs); //����� ������� ��� ��������� ��������� ��
			Sleep(step);
		}
	}
	/*� ���� ������, ���� ��-���� ������� � ������� ���� ��� �� ��������� ������� ����*/
}

void Game::Control(int &x, int &y, int prs) { //x � y - ��������� ������� ���������
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
		wrld.getline(world[i], 81); //�������, ��� ��� ������ ���������� ������� �� ����� �� �����������
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
