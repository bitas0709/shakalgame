#pragma once
class Unit
{
public:
	Unit();
	int hp, corx, cory; //количество жизней юнита, координаты юнита
	int spd, dmg; //скорость юнита, урон, наносимый юнитом
	int blk; //класс брони юнита
	char mod[20]; //модель юнита
	~Unit();
};

