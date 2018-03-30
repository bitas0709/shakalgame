#include "stdafx.h"
#include "Unit.h"

using namespace std;
Unit::Unit()
{
}

Unit::Unit(int Cor_X, int Cor_Y, int HP, int DMG, char *model)
{
	CorX = Cor_X;
	CorY = Cor_Y;
	hp = HP;
	dmg = DMG;
	Model = model;

}

void Unit::Move(int NewX, int NewY)
{
	cout << world[y][x];
}

void Unit::Attack()
{

}

void Unit::Get_Damage(int damage)
{
	hp -= damage;
	if (hp < 0) Die();
}

void Unit::Die()
{
}


Unit::~Unit()
{
}

