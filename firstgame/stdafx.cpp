// stdafx.cpp: исходный файл, содержащий только стандартные включаемые модули
// firstgame.pch будет использоваться в качестве предкомпилированного заголовка
// stdafx.obj будет содержать предварительно откомпилированные сведения о типе

#include "stdafx.h"

void MoveCursor(short x, short y) { //перемещение курсора
	CursorPos = { x, y };
	SetConsoleCursorPosition(hStdOut, CursorPos);
}
// TODO: Установите ссылки на любые требующиеся дополнительные заголовки в файле STDAFX.H
// , а не в данном файле
