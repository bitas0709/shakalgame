#pragma once
#include "Global.h"
#include <windows.h>
class Global
{
public:
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD CursorPos;
	int prs = 0; //��� ������� ������
	short ret = 0; //����������, ���������� � ���� ������������ �������� �������
	bool mtrue = false; //����������, ���������� �� ������� � ����
	int x = 0, y = 0; //��������� ���������� �������
	short mwx = 80, mwy = 25; //������� ���� �� ��������� (main window x, main window y)
	void MoveCursor(short x, short y); //������� ��� ����������� �������
	void SetWinProp(short mwx, short mwy); //������� ��� ��������� ���������� ������� (������� � �������)
	void Window(int mstr, int mchr, char mass[20][15] , int background);
	Global();
	~Global();
};

