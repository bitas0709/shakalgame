#pragma once
#include "stdafx.h"
using namespace std;
class World
{
public:
	int Wide, Length; //������� ����
	char **world; //������, � ������� �������� ���
	string *ImpassableObjects  = new string("1"); //������ � ������� �������� ������������ ��� ������ �������
	void GenerateFromFile(); //������� ��� ���������� ���� �� �����. � ������� ����� ����� ������������ ����� ���������� � ����������� ������ ��������� ����
	World();// �������� ��������� ���� � �������� ��������
	World(int length, int wide);// �������� ��������� ���� � �������� ��������
	~World();
};

