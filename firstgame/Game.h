#pragma once
#include "Global.h"
#include "World.h"
#include "Hero.h"
#include "World.h"
class Game : public Global
{
public:
	World *Arena; //�������� ��� �� �����
	Hero *Player; // �����
	short step = 100; //�����, ����� ������� ����� �������� ��������� ���� ���������
	int x=4, y=3; //���������� � �����, ��������� ����� � ���� X � Y
	int mx = 35, my = 10; //���������� ������� � ���� �� ���������
	void Mov(); //������� ��� ����������� �������
	void Control(int &x, int &y, int prs);
	Game();
	~Game();
};

