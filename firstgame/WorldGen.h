#pragma once
class WorldGen
{
public:
	char world[25][80]; //������� ���� - X=80, Y=25
	void Generator(); //������� ��� ���������� ���� �� �����. � ������� ����� ����� ������������ ����� ���������� � ����������� ������ ��������� ����
	WorldGen();
	~WorldGen();
};

