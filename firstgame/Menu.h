#pragma once
class Menu
{
public:
	bool mtrue = false; //переменная, отвечающая за запуск игры из меню. true - запуск
	int mx = 35, my = 10; //координаты курсора в меню по умолчанию
	int mwx = 80, mwy = 25; //размеры окна по умолчанию (main window x, main window y)
	static const short str = 4; //количество строк в меню
	static const short chr = 10; //количество символов в строке кнопки
	short wx = ((mwx - chr - 4) / 2), wy = ((mwy - str - 2) / 2);
	char butt[str][chr]; //массив, содержащий текст кнопок
	void wind(); //функция, отвечающая за отрисовку окон
	void about(); //функция, отвечающая за вывод окна с информацией о разработчиках
	Menu();
	~Menu();
};

