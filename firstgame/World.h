#pragma once
#include "Atlas.h"
class World
{
public:
	int Wide, Length; //������� ����
	char **world; //������, � ������� �������� ���
	string *ImpassableObjects = ImpassableObjectsTest; //������ � ������� �������� ������������ ��� ������ �������
	void GenerateFromFile(); //������� ��� ���������� ���� �� �����. � ������� ����� ����� ������������ ����� ���������� � ����������� ������ ��������� ����
	World();// �������� ��������� ���� � �������� ��������
	World(int length, int wide);// �������� ��������� ���� � �������� ��������
	~World();
};

