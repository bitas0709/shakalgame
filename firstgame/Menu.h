#pragma once
#include "Global.h"
class Menu : public Global
{
public:
	bool mtrue = false; //����������, ���������� �� ������ ���� �� ����. true - ������
	int prs = 0; //��� ������� ������
	int mx = 35, my = 10; //���������� ������� � ���� �� ���������
	static const short str = 4; //���������� ����� � ����
	static const short chr = 14; //���������� �������� � ������ ������
	short wx = ((mwx - chr - 4) / 2), wy = ((mwy - str - 2) / 2); //������� ����� ���� ����
	char butt[str][chr] = { { 'N','e','w',' ','g','a','m','e' },{ 'O','p','t','i','o','n','s' },{ 'A','b','o','u','t' },{ 'E','x','i','t' } };; //������, ���������� ����� ������
	void wind(); //�������, ���������� �� ��������� ����
	void key(); //�������, ���������� �� ��������� ������ � ����
	void about(); //�������, ���������� �� ����� ���� � ����������� � �������������
	Menu();
	~Menu();
};

