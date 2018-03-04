#pragma once
#include <windows.h>
class Unit
{
public:
	Unit();
	int hp, corx, cory; //количество жизней юнита, координаты юнита
	int spd, dmg; //скорость юнита, урон, наносимый юнитом
	int blk; //класс брони юнита
	char model; //модель юнита
	~Unit();
	void Mov(int NewX, int NewY);
};

