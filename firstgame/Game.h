#pragma once
#include "Menu.h"
#include "Global.h"
#include "WorldGen.h"

class Game : public Menu, public WorldGen
{
public:
	short step = 100; //�����, ����� ������� ����� �������� ��������� ���� ���������
	int x=10, y=10; //���������� � �����, ��������� ����� � ���� X � Y
	int mx = 35, my = 10; //���������� ������� � ���� �� ���������
	void Mov(); //������� ��� ����������� �������
	void Control(int &x, int &y, int prs);
	Game();
	~Game();
};

