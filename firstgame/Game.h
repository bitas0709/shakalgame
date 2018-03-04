#pragma once
#include "Menu.h"
#include "Global.h"
#include "WorldGen.h"

class Game : public Menu, public WorldGen
{
public:
	short step = 100; //время, через которое будет выполнен следуюший такт программы
	int x=10, y=10; //информация о герое, положение героя в осях X и Y
	int mx = 35, my = 10; //координаты курсора в меню по умолчанию
	bool mtrue = false; //переменная, отвечающая за запуск игры из меню
	int prs = 0; //код нажатой клавиши
	void Mov(); //функция для перемещения объекта
	//void Menu();
	void Control(int &x, int &y, int prs);
	Game();
	~Game();
};

