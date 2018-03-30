#pragma once
#include "stdafx.h"
#include <string>

using namespace std;
char *HeroModel =  new char[4]{ '^', '<', '>', 'V' }; //Возможные модели героев
string *ImpassableObjects = new string("1"); //Объекты, через которые пройти нельзя