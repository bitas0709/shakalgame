#pragma once
#include "Global.h"
#include "World.h"

class Game : public Global, public World
{
public:
	short step = 100; //�����, ����� ������� ����� �������� ��������� ���� ���������
	int x=4, y=3; //���������� � �����, ��������� ����� � ���� X � Y
	int mx = 35, my = 10; //���������� ������� � ���� �� ���������
	void Mov(); //������� ��� ����������� �������
	void Control(int &x, int &y, int prs);
	Game();
	~Game();
};

