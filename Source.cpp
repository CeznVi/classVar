#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include "class var.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	var a = 15;
	var b = "Hello";
	var c = 7.8;
	var d = "50";
	std::cout << "a = ";
	a.print();
	std::cout << "b = ";
	b.print();
	std::cout << "c = ";
	c.print();
	std::cout << "b = a + d = ";
	b = a + d;
	b.print();
	std::cout << "a == b == ";
		if(a == b)
			std::cout << "Дорівнює\n";
		else 
			std::cout << "Недорівнює\n";
	std::cout << "a += d = ";
	a += d;
	a.print();
	var e = "Microsoft";
	var f = "Windows";
	var g;
	std::cout << "e = ";
	e.print();
	std::cout << "f = ";
	f.print();
	std::cout << "g = e * f = ";
	g = e * f;
	g.print();
	std::cout << "g = e / f = ";
	g = e / f;
	g.print();

	return 0;
}