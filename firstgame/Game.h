#pragma once
class Game
{
public:
	short step = 100; //�����, ����� ������� ����� �������� ��������� ���� ���������
	int x=10, y=10; //���������� � �����, ��������� ����� � ���� X � Y
	int mx = 35, my = 10; //���������� ������� � ���� �� ���������
	bool mtrue = false; //����������, ���������� �� ������ ���� �� ����
	int prs = 0; //��� ������� �������
	char world[25][80]; //������� ���� - X=80, Y=25
	void MoveCursor(int x, int y); //������� ��� ����������� �������
	void Mov(); //������� ��� ����������� �������
	void Generator(); //������� ��� ���������� ���� �� �����. � ������� ����� ����� ������������ ����� ���������� � ����������� ������ ��������� ����
	void Menu();
	void Control(int &x, int &y, int prs);
	Game();
	~Game();
};

