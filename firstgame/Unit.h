#pragma once
#include <windows.h>
#include "Global.h"
#include "World.h"
class Unit
{
public:
	Unit();
	Unit(int Cor_X, int Cor_Y, int HP, int DMG, char *model);
	// Поведение
	void Attack(); //Нанесение урона
	void Get_Damage(int damage); //Получение урона
	void Die(); //Смерть
	void Move(int NewX, int NewY, World *Location); //Движение в новую точку с координатами, в заданной локации

	// Параметры
	int hp;//количество жизней юнита,
	int CorX, CorY;// координаты юнита
	int spd, dmg; //скорость юнита, урон, наносимый юнитом
	int blk; //класс брони юнита
	char *Model; //модель юнита
	~Unit();
};