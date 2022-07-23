#pragma once


class var {
private:
	int i{};
	double d{};
	char* c = nullptr;
	///змінна показчика класу
	int idVar = 0;
	/// список станів змінної var
	enum WhatIsIt
	{
		Null,
		Int,
		Double,
		Char,
	};

public:
	//конструктори 
	var();
	var(int a);
	var(double a);
	var(const char* a);
	var(const var& obj);
	var& operator=(const var& obj);
	//деструктор
	~var();
	//Метод друку об'єкту
	void print();
	//Сетер
	void setVar(int a);
	void setVar(double a);
	void setVar(const char* a);

	//Метод перевантаження (клас + клас = клас)
	var operator+(var& obj);

	//Метод перетворення Чар в Інт
	var charToInt();


};

///Конструктор пустишки
var::var()
{
	idVar = WhatIsIt::Null;
}
///Конструктор типу інт вар
var::var(int a)
{
	setVar(a);
}
///Конструктор тип дабл вар
var::var(double a)
{
	setVar(a);
}
///Конструктор типу чар вар
var::var(const char* a)
{
	setVar(a);
}
//коструктор копіювання
var::var(const var& obj)
{
	switch (idVar)
	{
	case WhatIsIt::Int:
		this->setVar(obj.i);
		break;
	case WhatIsIt::Double:
		this->setVar(obj.d);
		break;
	case WhatIsIt::Char:
		this->setVar(obj.c);
		break;
	default:
		break;
	}
}
//перевантаження оператора присвоення
var& var::operator=(const var& obj)
{
	if (this == &obj)
		return *this;

	this->~var();
	
	switch (obj.idVar)
	{
	case WhatIsIt::Int:
		this->setVar(obj.i);
		break;
	case WhatIsIt::Double:
		this->setVar(obj.d);
		break;
	case WhatIsIt::Char:
		this->setVar(obj.c);
		break;
	default:
		break;
	}

	return *this;

}
///Деструктор
var::~var()
{
	switch (idVar)
	{
	case WhatIsIt::Int:
		i = 0;
		break;
	case WhatIsIt::Double:
		d = 0;
		break;
	case WhatIsIt::Char:
		delete c;
		c = nullptr;
		break;
	default:
		break;
	}
}
///Метод друку об'єкту
void var::print()
{
	switch (idVar)
	{
	case WhatIsIt::Int:
		std::cout << i << '\n';
		break;
	case WhatIsIt::Double:
		std::cout << d << '\n';
		break;
	case WhatIsIt::Char:
		std::cout << c << '\n';
		break;
	default:
		break;
	}
}
//Інтовий сетер
void var::setVar(int a)
{
	i = a;
	idVar = WhatIsIt::Int;
}
//Дабловий сетер
void var::setVar(double a)
{
	d = a;
	idVar = WhatIsIt::Double;
}
//Чаровий сетер
void var::setVar(const char* a)
{
	delete c;
	c = new char[strlen(a) + 1];
	strcpy_s(c, strlen(a) + 1, a);
	idVar = WhatIsIt::Char;
}

var var::operator+(var& obj)
{
	//INT перший
	if (this->idVar == Int && obj.idVar == Int)
		return this->i + obj.i;
	else if (this->idVar == Int && obj.idVar == Double)
		return this->i + static_cast<int>(obj.d);
	else if (this->idVar == Int && obj.idVar == Char)
		return obj.charToInt();
		//return this->i + (int)obj.c;


	
	//Double перший
	else if (this->idVar == Double && obj.idVar == Double)
		return this->d + obj.d;
	else if (this->idVar == Double && obj.idVar == Int)
		return this->d + static_cast<double>(obj.i);
	//Сhar перший
	else if (this->idVar == Char && obj.idVar == Char)
		return strcpy_s(this->c, strlen(obj.c) + 1, obj.c);

	
	
	



}

var var::charToInt()
{
	if (idVar != Char)
		return 0;

	int temp = atoi(this->c);
	std::cout << "CHAR TO INT " << temp;


	return var();
}
