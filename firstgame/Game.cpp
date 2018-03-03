#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;


Game::Game() //�����������, � ������� � ���������� ���� ������� �������
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
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
	COORD CursorPos;
	if (prs == 119) { //������� �� ������ w
		if (y > 0) {
			MCursor(x, y);
			cout << world[y][x];
			y -= 1;
			MCursor(x, y);
			cout << "%";
		}
	}
	else if (prs == 97) { //������� �� ������ a
		if (x > 0) {
			MCursor(x, y);
			cout << world[y][x];
			x -= 1;
			MCursor(x, y);
			cout << "%";
		}
	}
	else if (prs == 115) { //������� �� ������ s
		if (y < 25) {
			MCursor(x, y);
			cout << world[y][x];
			y += 1;
			MCursor(x, y);
			cout << "%";
		}
	}
	else if (prs == 100) { //������� �� ������ d
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
		wrld.getline(world[i], 81); //�������, ��� ��� ������ ���������� ������� �� ����� �� �����������
		cout << world[i];
	}
	wrld.close();
}

void Game::Menu() {
	system("cls");
	bool mn = 0; //����������, ���������� �� ���������� ����� while
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
			else if (prs == 13) { //������� �� ������ Enter
				if (my == 10) { //����� ����
					mtrue = true;
					mn = 1;
				}
				else if (my == 11) { //�����
					/*�����. ���� � ����������*/
				}
				else if (my == 12) { //�� ����
					/*�� ����. ���� � ����������*/
				}
				else if (my == 13) { //����� �� ����
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
