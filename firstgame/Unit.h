#pragma once
#include <windows.h>
	class Unit
{
public:
	Unit();
	Unit(int Cor_X, int Cor_Y, int HP, int DMG, char *model);
	void Attack();
	void Get_Damage(int damage);
	void Die();
	int hp, CorX, CorY; //количество жизней юнита, координаты юнита
	int spd, dmg; //скорость юнита, урон, наносимый юнитом
	int blk; //класс брони юнита
	char *Model; //модель юнита
	~Unit();
	void Move(int NewX, int NewY);
};

