#pragma once
#include "Global.h"
#include <windows.h>
class Global
{
public:

	int prs = 0; //��� ������� ������
	short ret = 0; //����������, ���������� � ���� ������������ �������� �������
	bool mtrue = false; //����������, ���������� �� ������� � ����
	int x = 0, y = 0; //��������� ���������� �������
	short mwx = 80, mwy = 26; //������� ���� �� ��������� (main window x, main window y)
	static const short str = 4; //���������� ����� � ����
	static const short chr = 14; //���������� �������� � ������ ������
	char butt[str][chr] = { { 'N','e','w',' ','g','a','m','e' },{ 'O','p','t','i','o','n','s' },{ 'A','b','o','u','t' },{ 'E','x','i','t' } }; //������, ���������� ����� ������


//	void MoveCursor(short x, short y); //������� ��� ����������� �������
	void Window(int mstr, int mchr, char mass[20][14] , int background);
	Global();
	~Global();
};


