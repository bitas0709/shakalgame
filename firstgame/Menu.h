#pragma once
#include "Global.h"
class Menu : public Global
{
public:
	bool mtrue = false; //����������, ���������� �� ������ ���� �� ����. true - ������
	int mx = 35, my = 10; //���������� ������� � ���� �� ���������
	static const short str = 4; //���������� ����� � ����
	static const short chr = 10; //���������� �������� � ������ ������
	short wx = ((mwx - chr - 4) / 2), wy = ((mwy - str - 2) / 2); //�����, ��� ���
	char butt[str][chr]; //������, ���������� ����� ������
	void wind(); //�������, ���������� �� ��������� ����
	void key(); //�������, ���������� �� ��������� ������ � ����
	void about(); //�������, ���������� �� ����� ���� � ����������� � �������������
	Menu();
	~Menu();
};

