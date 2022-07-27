#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include "class var.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	var a = 2;
	var b = 2;
	var c = 3.045;
	var d;

	std::cout << "a =";
	a.print();
	std::cout << "b =";
	b.print();
	std::cout << "c =";
	c.print();

	//d = a / c;
	std::cout << "d =";
	d.print();
	if(a == b)
		std::cout << "a ==b";
	else 
		std::cout << "FALSE   a <b";
	return 0;
}