﻿#include "stdafx.h"
#include "Hero.h"
char *HeroModel = new char[4]{ '^', '<', '>', 'V' }; //Возможные модели героев

Hero::Hero()
{
}

Hero::Hero(int Cor_X, int Cor_Y) : Unit(Cor_X, Cor_Y, std_start_hp, std_start_dmg, HeroModel)
{

}

Hero::~Hero()
{
}
