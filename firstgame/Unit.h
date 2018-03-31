#pragma once
#include <windows.h>
#include "Global.h"
#include "World.h"
class Unit
{
public:
	Unit();
	Unit(int Cor_X, int Cor_Y, int HP, int DMG, char *model);
	// ���������
	void Attack(); //��������� �����
	void Get_Damage(int damage); //��������� �����
	void Die(); //������
	void Move(int NewX, int NewY, World *Location); //�������� � ����� ����� � ������������, � �������� �������

	// ���������
	int hp;//���������� ������ �����,
	int CorX, CorY;// ���������� �����
	int spd, dmg; //�������� �����, ����, ��������� ������
	int blk; //����� ����� �����
	char *Model; //������ �����
	~Unit();
};