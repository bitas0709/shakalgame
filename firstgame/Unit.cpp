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

void Unit::Move(int NewX, int NewY, World *Location)
{
	if (Location->ImpassableObjects->find(Location->world[NewY][NewX]) == -1) // Проверка на то, что точка назначения не является "стеной"
	{
		cout << Location->world[CorY][CorX];
		MoveCursor(NewX, NewY);
		
		//Возможно это стоит вынести в отдельную функцию поворота, с отдельной кнопкой, например стрелками
		if (NewY > CorY) cout << Model[0];
		else if (NewX < CorX) cout << Model[1];
		else if (NewX > CorX) cout << Model[2];
		else cout << Model[3];
	}
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

