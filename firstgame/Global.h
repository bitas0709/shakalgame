#pragma once
class Global
{
public:
	int x = 0, y = 0; //��������� ���������� �������
	int mwx = 80, mwy = 25; //������� ���� �� ��������� (main window x, main window y)
	void MoveCursor(int x, int y); //������� ��� ����������� �������
	void setwinprop(); //������� ��� ��������� ���������� ������� (������� � �������)
	Global();
	~Global();
};

