#include "stdafx.h"
#include "WorldGen.h"
#include <fstream>
#include <iostream>
using namespace std;


WorldGen::WorldGen()
{
}

void WorldGen::Generator() {
	ifstream wrld("world.txt"); //�������� �����, ����������� ���
	for (int i = 0; i < 25; i++) {
		wrld.getline(world[i], 51); //�������, ��� ��� ������ ���������� ������� �� ����� �� �����������
		cout << world[i] << endl; //����� ���� �� �����
	}
	wrld.close();
}

WorldGen::~WorldGen()
{
}
