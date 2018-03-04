#pragma once
class Global
{
public:
	int x = 0, y = 0; //начальные координаты курсора
	int mwx = 80, mwy = 25; //размеры окна по умолчанию (main window x, main window y)
	void MoveCursor(int x, int y); //функция для перемещения курсора
	void setwinprop(); //функция для установки параметров консоли (размера и прочего)
	Global();
	~Global();
};

