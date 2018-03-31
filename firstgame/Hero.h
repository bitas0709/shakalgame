#pragma once
#include "Unit.h"

#define std_start_hp 100 //тестовый параметр здоровья
#define std_start_dmg 1 //тестовый параметр урона

class Hero :
	public Unit
{
public:
	Hero();
	Hero(int Cor_X, int Cor_Y); //Создание героя с заданными координатами
	~Hero();
};

