#pragma once
#include <windows.h>
#include "Global.h"
#include "WorldGen.h"
class Unit
{
public:
	Unit();
	Unit(int Cor_X, int Cor_Y, int HP, int DMG, char *model);
	// ���������
	void Attack(); //��������� �����
	void Get_Damage(int damage); //��������� �����
	void Die(); //������
	void Move(int NewX, int NewY); //�������� � ����� ����� � ������������

	// ���������
	int hp;//���������� ������ �����,
	int CorX, CorY;// ���������� �����
	int spd, dmg; //�������� �����, ����, ��������� ������
	int blk; //����� ����� �����
	char *Model; //������ �����
	~Unit();
};