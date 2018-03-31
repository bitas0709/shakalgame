#include "stdafx.h"
#include "World.h"
#include <fstream>
#include <iostream>
#define TestWorldLength 25
#define TestWorldWide 50
using namespace std;


World::World() 
{
	Length = TestWorldLength;
	Wide = TestWorldWide;
	GenerateFromFile();
}
World::World(int length, int wide) 
{
	Length = length;
	Wide = wide;	
}
void World::GenerateFromFile() 
{

	world = new char*[Length];
	for (int i = 0; i < Length; i++)
		world[i] = new char[Wide];

	ifstream wrld("world.txt"); //открытие файла, содержащего мир
	for (int i = 0; i < Length; i++) 
	{
		wrld.getline(world[i], Wide + 1); //костыль, так как чтение последнего символа из файла не происходило // Ведь в конце строки символ перехода на следущую
		cout << world[i] << endl; //вывод мира на экран
	}
	wrld.close();
}

World::~World()
{
}
