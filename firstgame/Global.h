#pragma once
#include "Global.h"
#include <windows.h>
class Global
{
public:
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD CursorPos;
	int x = 0, y = 0; //��������� ���������� �������
	int mwx = 80, mwy = 25; //������� ���� �� ��������� (main window x, main window y)
	void MoveCursor(short x, short y); //������� ��� ����������� �������
	void SetWinProp(); //������� ��� ��������� ���������� ������� (������� � �������)
	Global();
	~Global();
};

