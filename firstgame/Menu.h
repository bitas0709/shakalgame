#pragma once
class Menu
{
public:
	bool mtrue = false; //����������, ���������� �� ������ ���� �� ����. true - ������
	int mx = 35, my = 10; //���������� ������� � ���� �� ���������
	int mwx = 80, mwy = 25; //������� ���� �� ��������� (main window x, main window y)
	static const short str = 4; //���������� ����� � ����
	static const short chr = 10; //���������� �������� � ������ ������
	short wx = ((mwx - chr - 4) / 2), wy = ((mwy - str - 2) / 2);
	char butt[str][chr]; //������, ���������� ����� ������
	void wind(); //�������, ���������� �� ��������� ����
	void about(); //�������, ���������� �� ����� ���� � ����������� � �������������
	Menu();
	~Menu();
};

