#pragma once
#include "stdafx.h"
#include <string>
//Файл, в котором хранятся разные модели
using namespace std;
char *HeroModel =  new char[4]{ '^', '<', '>', 'V' }; //Возможные модели героев
string *ImpassableObjectsTest = new string("1"); //Объекты, через которые пройти нельзя