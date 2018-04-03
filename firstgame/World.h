#pragma once
#include "stdafx.h"
using namespace std;
class World
{
public:
	int Wide, Length; //Размеры мира
	char **world; //Массив, в котором хранится мир
	string *ImpassableObjects  = new string("1"); //Массив в котором хранятся непроходимые для юнитов объекты
	void GenerateFromFile(); //функция для считывания мира из файла. В будущем нужно будет организовать более безопасный и эффективный способ генерации мира
	World();// Создание тестового мира с тестовым размером
	World(int length, int wide);// Создание тестового мира с заданным размером
	~World();
};

