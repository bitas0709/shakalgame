#pragma once
#include "Unit.h"
#define std_start_hp 100
#define std_start_dmg 1
class Hero :
	public Unit
{
public:
	Hero();
	Hero(int Cor_X, int Cor_Y) : Unit(Cor_X, Cor_Y, std_start_hp, std_start_dmg, );
	~Hero();
};

