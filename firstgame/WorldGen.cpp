#include "stdafx.h"
#include "WorldGen.h"
#include <fstream>
#include <iostream>
using namespace std;


WorldGen::WorldGen()
{
}

void WorldGen::Generator() {
	ifstream wrld("world.txt"); //открытие файла, содержащего мир
	for (int i = 0; i < 25; i++) {
		wrld.getline(world[i], 51); //костыль, так как чтение последнего символа из файла не происходило
		cout << world[i] << endl; //вывод мира на экран
	}
	wrld.close();
}

WorldGen::~WorldGen()
{
}
