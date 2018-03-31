#include "stdafx.h"
#include "World.h"
#include <fstream>
#include <iostream>
#define TestWorldLength 25
#define TestWorldWide 50
using namespace std;


World::World() 
{
	Length = TestWorldLength;
	Wide = TestWorldWide;
	GenerateFromFile();
}
World::World(int length, int wide) 
{
	Length = length;
	Wide = wide;	
}
void World::GenerateFromFile() 
{

	world = new char*[Length];
	for (int i = 0; i < Length; i++)
		world[i] = new char[Wide];

	ifstream wrld("world.txt"); //�������� �����, ����������� ���
	for (int i = 0; i < Length; i++) 
	{
		wrld.getline(world[i], Wide + 1); //�������, ��� ��� ������ ���������� ������� �� ����� �� ����������� // ���� � ����� ������ ������ �������� �� ��������
		cout << world[i] << endl; //����� ���� �� �����
	}
	wrld.close();
}

World::~World()
{
}
