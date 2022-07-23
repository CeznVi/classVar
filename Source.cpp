#include <iostream>
#include <stdlib.h>
#include "class var.h"

int main()
{
	var a = 22;
	var b = 3.045;
	var c{ "11s"};
	var d = 0;

	std::cout << "a =";
	a.print();
	std::cout << "b =";
	b.print();
	std::cout << "c =";
	c.print();

	d += c;
	std::cout << "d =";
	d.print();

	return 0;
}