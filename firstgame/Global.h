#pragma once
#include "Global.h"
#include <windows.h>
class Global
{
public:
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD CursorPos;
	int prs = 0; //код нажатой кнопки
	short ret = 0; //переменная, содержащая в себе возвращённое значение функции
	bool mtrue = false; //переменная, отвечающая за переход в игру
	int x = 0, y = 0; //начальные координаты курсора
	short mwx = 80, mwy = 26; //размеры окна по умолчанию (main window x, main window y)
	static const short str = 4; //количество строк в меню
	static const short chr = 14; //количество символов в строке кнопки
	char butt[str][chr] = { { 'N','e','w',' ','g','a','m','e' },{ 'O','p','t','i','o','n','s' },{ 'A','b','o','u','t' },{ 'E','x','i','t' } }; //массив, содержащий текст кнопок


	void MoveCursor(short x, short y); //функция для перемещения курсора
	void SetWinProp(); //функция для установки параметров консоли (размера и прочего). При изменении mwx и mwy, их стоит поменять и здесь
	void Window(int mstr, int mchr, char mass[20][14] , int background);
	Global();
	~Global();
};

class Unit
{
public:
	Unit();
	int hp, corx, cory; //количество жизней юнита, координаты юнита
	int spd, dmg; //скорость юнита, урон, наносимый юнитом
	int blk; //класс брони юнита
	char model[5] = { '^', '<', '>', 'V', '*' }; //модель юнита
	~Unit();
	void Mov(int NewX, int NewY);
};

