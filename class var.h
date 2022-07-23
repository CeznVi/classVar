#pragma once


class var {
private:
	int i{};
	double d{};
	char* c = nullptr;
	///����� ��������� �����
	int idVar = 0;
	/// ������ ����� ����� var
	enum WhatIsIt
	{
		Null,
		Int,
		Double,
		Char,
	};

	char* charPlus(var obj);
	//����� ������������ ��� � ���
	int charToInt();
	//����� ������������ ��� � ����
	double charToDouble();
	char* intToChar(int n);
	char* doubleToChar(double n);

public:
	//������������ 
	var();
	var(int a);
	var(double a);
	var(const char* a);
	var(const var& obj);
	var& operator=(const var& obj);
	//����������
	~var();
	//����� ����� ��'����
	void print();
	//�����
	void setVar(int a);
	void setVar(double a);
	void setVar(const char* a);

	//����� �������������� (���� + ���� = ����)
	var operator+(var& obj);





};

///����������� ��������
var::var()
{
	idVar = WhatIsIt::Null;
}
///����������� ���� ��� ���
var::var(int a)
{
	setVar(a);
}
///����������� ��� ���� ���
var::var(double a)
{
	setVar(a);
}
///����������� ���� ��� ���
var::var(const char* a)
{
	setVar(a);
}
//���������� ���������
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
//�������������� ��������� ����������
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
///����������
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
///����� ����� ��'����
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
//������� �����
void var::setVar(int a)
{
	i = a;
	idVar = WhatIsIt::Int;
}
//�������� �����
void var::setVar(double a)
{
	d = a;
	idVar = WhatIsIt::Double;
}
//������� �����
void var::setVar(const char* a)
{
	delete c;
	c = new char[strlen(a) + 1];
	strcpy_s(c, strlen(a) + 1, a);
	idVar = WhatIsIt::Char;
}
//����� �������������� (���� + ���� = ����)
var var::operator+(var& obj)
{
	//INT ������
	if (this->idVar == Int && obj.idVar == Int)
		return this->i + obj.i;
	else if (this->idVar == Int && obj.idVar == Double)
		return this->i + static_cast<int>(obj.d);
	else if (this->idVar == Int && obj.idVar == Char)
		return this->i + obj.charToInt();
	//Double ������
	else if (this->idVar == Double && obj.idVar == Double)
		return this->d + obj.d;
	else if (this->idVar == Double && obj.idVar == Int)
		return this->d + static_cast<double>(obj.i);
	else if (this->idVar == Double && obj.idVar == Char)
		return this->d + obj.charToDouble();
	//�har ������
	else if (this->idVar == Char && obj.idVar == Char)
		return this->charPlus(obj.c);
	else if (this->idVar == Char && obj.idVar == Int)
		return this->charPlus(obj.i);
	else if (this->idVar == Char && obj.idVar == Double)
		return this->charPlus(obj.d);
	else
		return 0;
}
//������������ ��� �� ���
int var::charToInt()
{
	if (idVar != Char)
		return 0;

	int temp = atoi(this->c);
	return temp;
}
//������������ ��� �� Double
double var::charToDouble()
{
	if (idVar != Char)
		return 0;

	double temp = atof(this->c);
	return temp;
}
///������������ ���� � ��� (�������� �� ������������)
char* var::intToChar(int n)
{
	char s[20] = { 0 };
	char* c = s + 19;
	unsigned int m = n;
	int sign;
	if (n < 0) {
		m = -n;
		sign = -1;
	}
	else if (n == 0) sign = 0;
	else sign = 1;
	if (m == 0) *--c = '0';
	else
	{
		for (; m; m /= 10) *--c = m % 10 + '0';
		if (sign < 0)   *--c = '-';
	}
	char* r = new char[s + 20 - c];
	char* q = r;
	while (*q++ = *c++);
	return r;
}

char* var::charPlus(var obj)
{
	if (obj.idVar == Char)
	{
		size_t length = strlen(this->c) + strlen(obj.c);
		char* temp = new char[length];
		for (int i{}; i < strlen(this->c); i++)
			temp[i] = this->c[i];

		for (int i{}; i < strlen(obj.c) + 1; i++)
			temp[strlen(this->c) + i] = obj.c[i];

		return temp;
	}
	else if (obj.idVar == Int)
	{

		char* ch = intToChar(obj.i);
		size_t length = strlen(this->c) + strlen(ch);
		char* temp = new char[length];
		for (int i{}; i < strlen(this->c); i++)
			temp[i] = this->c[i];

		for (int i{}; i < strlen(ch) + 1; i++)
			temp[strlen(this->c) + i] = ch[i];

		return temp;
	}
	else if (obj.idVar == Double)
	{
		return this->c;
	}
	else
		return 0;


}

//size_t returnStrLenght(int obj)
//{
//	size_t length{};
//	char* ch = new char{ static_cast<char>(obj) };
//	length = strlen(ch);
//	delete[] ch;
//	return length;
//}
//
//char* var::charPlus(int obj)
//{
//
//	size_t length = strlen(this->c) + returnStrLenght(obj);
//	char* temp = new char[length];
//
//	for (int i{}; i < strlen(this->c); i++)
//		temp[i] = this->c[i];
//
//	//for (int i{}; i < strlen(obj) + 1; i++)
//	//	temp[strlen(this->c) + i] = obj[i];
//
//	return temp;
//}



