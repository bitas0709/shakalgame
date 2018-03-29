#pragma once
#include "Global.h"
#include "WorldGen.h"

class Game : public Global, public WorldGen, public Unit
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

