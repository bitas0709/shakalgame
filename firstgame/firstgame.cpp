/*игра с видом сверху, где игрок должен убить всех врагов на карте. У врагов в этой версии игры не должно быть ИИ. Так же в данной версии игры нет стен.
Необходимо разработать: меню в игре, управление игроком, спаун 10 врагов в разных местах не ближе 5 блоков к начальной точке игрока, стены,
нормальную генерацию мира или написать несколько файлов с мирами, и, в качестве вишенки на торте, подключить графику с изображением из атласа (картинки, состоящей из кучи мелких картинок*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "Game.h"
using namespace std;

int main()
{
	static const TCHAR* title = TEXT("shakalgame.v0.00001");
	SetConsoleTitle(title);
	Game();
	//system("pause");
    return 0;
}

