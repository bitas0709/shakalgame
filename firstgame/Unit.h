#pragma once
#include <windows.h>
class Unit
{
public:
	Unit();
	int hp, corx, cory; //���������� ������ �����, ���������� �����
	int spd, dmg; //�������� �����, ����, ��������� ������
	int blk; //����� ����� �����
	char model[5] = { '^', '<', '>', 'V', '*' }; //������ �����
	~Unit();
	void Mov(int NewX, int NewY);
};

