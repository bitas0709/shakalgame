#pragma once
class Unit
{
public:
	Unit();
	int hp, corx, cory; //���������� ������ �����, ���������� �����
	int spd, dmg; //�������� �����, ����, ��������� ������
	int blk; //����� ����� �����
	char mod[20]; //������ �����
	~Unit();
};

