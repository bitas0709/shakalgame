// stdafx.h: включаемый файл для стандартных системных включаемых файлов
// или включаемых файлов для конкретного проекта, которые часто используются, но
// не часто изменяются
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>


#include <iostream>
#include <conio.h>
#include <Windows.h>
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPos;
void MoveCursor(short x, short y);
// TODO: Установите здесь ссылки на дополнительные заголовки, требующиеся для программы
