#include "stdafx.h"
#include "Game.h"
#include "Menu.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;

Game::Game() //�����������, � ������� � ���������� ���� ������� �������
{
	//Game::Menu();
	Game::wind();
	if (mtrue == true) {
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(hStdOut, &structCursorInfo);
		structCursorInfo.bVisible = false;
		SetConsoleCursorInfo(hStdOut, &structCursorInfo);
		//COORD CursorPos;
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
	//COORD CursorPos;
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

//void Game::Menu() {
//	system("cls");
//	bool mn = 0; //����������, ���������� �� ���������� ����� while
//	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_CURSOR_INFO structCursorInfo;
//	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
//	structCursorInfo.bVisible = false;
//	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
//	COORD CursorPos;
//	MoveCursor(34, 8);
//	cout << "+----------+" << endl;
//	MoveCursor(34, 9);
//	cout << "|          |" << endl;
//	MoveCursor(34, 10);
//	cout << "| New Game |" << endl;
//	MoveCursor(34, 11);
//	cout << "| Options  |" << endl;
//	MoveCursor(34, 12);
//	cout << "| About    |" << endl;
//	MoveCursor(34, 13);
//	cout << "| Exit     |" << endl;
//	MoveCursor(34, 14);
//	cout << "|          |" << endl;
//	MoveCursor(34, 15);
//	cout << "+----------+" << endl;
//	MoveCursor(mx, my);
//	cout << "*";
//	MoveCursor(mx + 9, my); // ��� ��������
//	//CursorPos.X = mx + 9;
//	//SetConsoleCursorPosition(hStdOut, CursorPos);
//	cout << "*";
//	while (mn == 0) {
//		if (_kbhit() == 0) {
//			Sleep(100);
//		}
//		else {
//			prs = _getch();
//			if (prs == 119) {
//				if (my > 10) {
//					MoveCursor(mx, my);
//					//CursorPos.X = mx;
//					//CursorPos.Y = my;
//					//SetConsoleCursorPosition(hStdOut, CursorPos);
//					cout << " ";
//					MoveCursor(mx + 9, my); // ��� ��������
//					//CursorPos.X = mx + 9;
//					//SetConsoleCursorPosition(hStdOut, CursorPos);
//					cout << " ";
//					my -= 1;
//					MoveCursor(mx, my);
//					//CursorPos.X = mx;
//					//CursorPos.Y = my;
//					//SetConsoleCursorPosition(hStdOut, CursorPos);
//					cout << "*";
//					MoveCursor(mx + 9, my); // ��� ��������
//					//CursorPos.X = mx + 9;
//					//SetConsoleCursorPosition(hStdOut, CursorPos);
//					cout << "*";
//				}
//			}
//			else if (prs == 115) {
//				if (my < 13) {
//					MoveCursor(mx, my);
//					//CursorPos.X = mx;
//					//CursorPos.Y = my;
//					//SetConsoleCursorPosition(hStdOut, CursorPos);
//					cout << " ";
//					MoveCursor(mx + 9, my); // ��� ��������
//					//CursorPos.X = mx + 9;
//					//SetConsoleCursorPosition(hStdOut, CursorPos);
//					cout << " ";
//					my += 1;
//					MoveCursor(mx, my);
//					//CursorPos.X = mx;
//					//CursorPos.Y = my;
//					//SetConsoleCursorPosition(hStdOut, CursorPos);
//					cout << "*";
//					MoveCursor(mx + 9, my); // ��� ��������
//					//CursorPos.X = mx + 9;
//					//SetConsoleCursorPosition(hStdOut, CursorPos);
//					cout << "*";
//				}
//			}
//			else if (prs == 13) { //������� �� ������ Enter
//				if (my == 10) { //����� ����
//					mtrue = true;
//					mn = 1;
//				}
//				else if (my == 11) { //�����
//					/*�����. ���� � ����������*/
//				}
//				else if (my == 12) { //�� ����
//					/*�� ����. ���� � ����������*/
//				}
//				else if (my == 13) { //����� �� ����
//					mn = 1;
//				}
//			}
//		}
//	}
//}

void Game::Mov() {

}


Game::~Game()
{
}
