#pragma once
#include "Global.h"
#include "World.h"

class Game : public Global, public World
{
public:
	short step = 100; //время, через которое будет выполнен следуюший такт программы
	int x=4, y=3; //информация о герое, положение героя в осях X и Y
	int mx = 35, my = 10; //координаты курсора в меню по умолчанию
	void Mov(); //функция для перемещения объекта
	void Control(int &x, int &y, int prs);
	Game();
	~Game();
};

