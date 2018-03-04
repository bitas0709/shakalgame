#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;

void Game::MoveCursor(int x,int y) { //����������� �������
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD CursorPos = { x, y };
	SetConsoleCursorPosition(hStdOut, CursorPos);
}

Game::Game() //�����������, � ������� � ���������� ���� ������� �������
{
	Game::Menu();
	if (mtrue == true) {
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(hStdOut, &structCursorInfo);
		structCursorInfo.bVisible = false;
		SetConsoleCursorInfo(hStdOut, &structCursorInfo);
		COORD crd = { 80, 25 };
		SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
		SetConsoleWindowInfo(hStdOut, true, &src);
		SetConsoleScreenBufferSize(hStdOut, crd);
		COORD CursorPos;
		MoveCursor(0, 0);
		Game::Generator();
		MoveCursor(0, 0);
		MoveCursor(x, y);
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
			MoveCursor(x, y);
			cout << world[y][x];
			y -= 1;
			MoveCursor(x, y);
			cout << "%";
		}
	}
	else if (prs == 97) { //������� �� ������ a
		if (x > 0) {
			MoveCursor(x, y);
			cout << world[y][x];
			x -= 1;
			MoveCursor(x, y);
			cout << "%";
		}
	}
	else if (prs == 115) { //������� �� ������ s
		if (y < 24) {
			MoveCursor(x, y);
			cout << world[y][x];
			y += 1;
			MoveCursor(x, y);
			cout << "%";
		}
	}
	else if (prs == 100) { //������� �� ������ d
		if (x < 79) {
			MoveCursor(x, y);
			cout << world[y][x];
			x += 1;
			MoveCursor(x, y);
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
	MoveCursor(34, 8);
	//CursorPos.X = 34;
	//CursorPos.Y = 8;
	//SetConsoleCursorPosition(hStdOut, CursorPos);
	cout << "+----------+" << endl;
	MoveCursor(34, 9);
	//CursorPos.X = 34;
	//CursorPos.Y = 9;
	//SetConsoleCursorPosition(hStdOut, CursorPos);
	cout << "|          |" << endl;
	MoveCursor(34, 10);
	//CursorPos.X = 34;
	//CursorPos.Y = 10;
	//SetConsoleCursorPosition(hStdOut, CursorPos);
	cout << "| New Game |" << endl;
	MoveCursor(34, 11);
	//CursorPos.X = 34;
	//CursorPos.Y = 11;
	//SetConsoleCursorPosition(hStdOut, CursorPos);
	cout << "| Options  |" << endl;
	MoveCursor(34, 12);
	//CursorPos.X = 34;
	//CursorPos.Y = 12;
	//SetConsoleCursorPosition(hStdOut, CursorPos);
	cout << "| About    |" << endl;
	MoveCursor(34, 13);
	//CursorPos.X = 34;
	//CursorPos.Y = 13;
	//SetConsoleCursorPosition(hStdOut, CursorPos);
	cout << "| Exit     |" << endl;
	MoveCursor(34, 14);
	//CursorPos.X = 34;
	//CursorPos.Y = 14;
	//SetConsoleCursorPosition(hStdOut, CursorPos);
	cout << "|          |" << endl;
	MoveCursor(34, 15);
	//CursorPos.X = 34;
	//CursorPos.Y = 15;
	//SetConsoleCursorPosition(hStdOut, CursorPos);
	cout << "+----------+" << endl;
	MoveCursor(mx, my);
	//CursorPos.X = mx;
	//CursorPos.Y = my;
	//SetConsoleCursorPosition(hStdOut, CursorPos);
	cout << "*";
	MoveCursor(mx + 9, my); // ��� ��������
	//CursorPos.X = mx + 9;
	//SetConsoleCursorPosition(hStdOut, CursorPos);
	cout << "*";
	while (mn == 0) {
		if (_kbhit() == 0) {
			Sleep(100);
		}
		else {
			prs = _getch();
			if (prs == 119) {
				if (my > 10) {
					MoveCursor(mx, my);
					//CursorPos.X = mx;
					//CursorPos.Y = my;
					//SetConsoleCursorPosition(hStdOut, CursorPos);
					cout << " ";
					MoveCursor(mx + 9, my); // ��� ��������
					//CursorPos.X = mx + 9;
					//SetConsoleCursorPosition(hStdOut, CursorPos);
					cout << " ";
					my -= 1;
					MoveCursor(mx, my);
					//CursorPos.X = mx;
					//CursorPos.Y = my;
					//SetConsoleCursorPosition(hStdOut, CursorPos);
					cout << "*";
					MoveCursor(mx + 9, my); // ��� ��������
					//CursorPos.X = mx + 9;
					//SetConsoleCursorPosition(hStdOut, CursorPos);
					cout << "*";
				}
			}
			else if (prs == 115) {
				if (my < 13) {
					MoveCursor(mx, my);
					//CursorPos.X = mx;
					//CursorPos.Y = my;
					//SetConsoleCursorPosition(hStdOut, CursorPos);
					cout << " ";
					MoveCursor(mx + 9, my); // ��� ��������
					//CursorPos.X = mx + 9;
					//SetConsoleCursorPosition(hStdOut, CursorPos);
					cout << " ";
					my += 1;
					MoveCursor(mx, my);
					//CursorPos.X = mx;
					//CursorPos.Y = my;
					//SetConsoleCursorPosition(hStdOut, CursorPos);
					cout << "*";
					MoveCursor(mx + 9, my); // ��� ��������
					//CursorPos.X = mx + 9;
					//SetConsoleCursorPosition(hStdOut, CursorPos);
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


Game::~Game()
{
}
