#pragma once
class WorldGen
{
public:
	char world[25][80]; //размеры мира - X=80, Y=25
	void Generator(); //функция для считывания мира из файла. В будущем нужно будет организовать более безопасный и эффективный способ генерации мира
	WorldGen();
	~WorldGen();
};

