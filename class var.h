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

	//����� ������������ ��� � ���
	var charToInt();


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

var var::operator+(var& obj)
{
	//INT ������
	if (this->idVar == Int && obj.idVar == Int)
		return this->i + obj.i;
	else if (this->idVar == Int && obj.idVar == Double)
		return this->i + static_cast<int>(obj.d);
	else if (this->idVar == Int && obj.idVar == Char)
		return obj.charToInt();
		//return this->i + (int)obj.c;


	
	//Double ������
	else if (this->idVar == Double && obj.idVar == Double)
		return this->d + obj.d;
	else if (this->idVar == Double && obj.idVar == Int)
		return this->d + static_cast<double>(obj.i);
	//�har ������
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
