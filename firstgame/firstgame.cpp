/*игра с видом сверху, где игрок должен убить всех врагов на карте. У врагов в этой версии игры не должно быть ИИ.
Необходимо разработать: спаун 10 врагов в разных местах не ближе 5 блоков к начальной точке игрока, стены,
нормальную генерацию мира или написать несколько файлов с мирами, и, в качестве вишенки на торте, подключить графику с изображением из атласа (картинки, состоящей из кучи мелких картинок*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "Game.h"
#include "Global.h"
using namespace std;

int main()
{
	Global();
	Game();
	system("pause");
    return 0;
}

