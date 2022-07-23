#include <iostream>
#include <stdlib.h>
#include "class var.h"

int main()
{
	var a = 10;
	var b = 3.00045;
	var c{ "s120twl" };
	var d;

	std::cout << "a =";
	a.print();
	std::cout << "b =";
	b.print();
	std::cout << "c =";
	c.print();

	d = a + c;
	//std::cout << "d =\n";
	d.print();

	return 0;
}