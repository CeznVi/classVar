#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include "class var.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	var a = "3.045z";
	var b = 21;
	var c = 3.045;
	var d;

	std::cout << "a =";
	a.print();
	std::cout << "b =";
	b.print();
	std::cout << "c =";
	c.print();

	d = a / c;
	std::cout << "d =";
	d.print();

	return 0;
}