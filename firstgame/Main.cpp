/*игра с видом сверху, где игрок должен убить всех врагов на карте. У врагов в этой версии игры не должно быть ИИ.
Необходимо разработать: спаун 10 врагов в разных местах не ближе 20 блоков к начальной точке игрока,
нормальную генерацию мира или написать несколько файлов с мирами, и, в качестве вишенки на торте, подключить графику с изображением из атласа (картинки, состоящей из кучи мелких картинок)*/

//Мне кажется, или Main.* здесь как-то больше не используются? Всё то, что должно было делаться в Menu, теперь делается в Global.
//По непонятным причинам, отрисовка уровня происходит корректно только на Windows 10. Надо бы решить эту проблему

//Противник должен распознавать зону 5х5 вокруг себя для передвижения. Перемещаться раз в 2 секунды по 4 шага, когда нет героя в зоне видимости.
//Направление движения зависит от нахождения стен в зоне 5х5, но в целом случайно.
//Так же нужно сделать зону видимости врага, то есть то, что он видит перед собой. Эта зона не должна превышать 15 блоков, и так же обязана ограничиваться стеной.

/*Расшифровка цветов:
0 = Black 8 = Gray
1 = Blue 9 = Light Blue
2 = Green A = Light Green
3 = Aqua B = Light Aqua
4 = Red C = Light Red
5 = Purple D = Light Purple
6 = Yellow E = Light Yellow
7 = White F = Bright White*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include "Game.h"
#include "Global.h"

using namespace std;



HANDLE hStdOut;
COORD CursorPos;
void MoveCursor(short x, short y) { //перемещение курсора
	CursorPos = { x, y };
	SetConsoleCursorPosition(hStdOut, CursorPos);
}

int main()
{
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	system("color 90");
	Global();
	Game();
	//system("pause");
    return 0;
}

