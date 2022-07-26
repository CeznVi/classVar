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
	//����� ��������� ���
	char* charPlus(var obj);
	//����� �������� ���
	char* charMinus(var obj);
	//����� * ���
	char* charMult(var obj);
	//����� / ���
	char* charDiv(var obj);
	//����� ������������ ��� � ���
	int charToInt();
	//����� ������������ ��� � ����
	double charToDouble();
	//����� ������������ ���, ���� � ���
	char* toChar(int n);
	char* toChar(double n);

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

	//����� �������������� ���������
	var operator+(var& obj);
	var operator+=(var& obj);
	var operator-(var& obj);
	var operator-=(var& obj);
	var operator*(var& obj);
	var operator*=(var& obj);
	var operator/(var& obj);

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
		idVar = Null;
		i = 0;
		break;
	case WhatIsIt::Double:
		idVar = Null;
		d = 0;
		break;
	case WhatIsIt::Char:
		delete c;
		c = nullptr;
		idVar = Null;
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
	idVar = WhatIsIt::Char;
	delete c;
	c = new char[strlen(a) + 1];
	strcpy_s(c, strlen(a) + 1, a);

}
//����� �������������� ���������
var var::operator+(var& obj)
{
	//������ ������
	if (this->idVar == Null && obj.idVar == Int)
		return obj.i;
	else if (this->idVar == Null && obj.idVar == Double)
		return obj.d;
	else if (this->idVar == Null && obj.idVar == Char)
		return obj.c;
	//INT ������
	else if (this->idVar == Int && obj.idVar == Int)
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
var var::operator+=(var& obj)
{	
	return *this = *this + obj;
}
var var::operator-(var& obj)
{
	//Var ������ ������, ����� �������� ������� � ������ "-", ��� ������ ���
	if (this->idVar == Null && obj.idVar == Int)
		return -obj.i;
	else if (this->idVar == Null && obj.idVar == Double)
		return -obj.d;
	else if (this->idVar == Null && obj.idVar == Char)
		return obj.c;
	//INT ������
	else if (this->idVar == Int && obj.idVar == Int)
		return this->i - obj.i;
	else if (this->idVar == Int && obj.idVar == Double)
		return this->i - static_cast<int>(obj.d);
	else if (this->idVar == Int && obj.idVar == Char)
		return this->i - obj.charToInt();	
	//Double ������
	else if (this->idVar == Double && obj.idVar == Double)
		return this->d - obj.d;
	else if (this->idVar == Double && obj.idVar == Int)
		return this->d - static_cast<double>(obj.i);
	else if (this->idVar == Double && obj.idVar == Char)
		return this->d - obj.charToDouble();
	//�har ������ 
	//���� ������ ��� �� ��� (�� �� ������� ���� ����������� ���� ������� � ����� ����)
	else if (this->idVar == Char && obj.idVar == Char)
		return this->charMinus(obj.c);
	else if (this->idVar == Char && obj.idVar == Int)
		return this->charMinus(obj.i);
	else if (this->idVar == Char && obj.idVar == Double)
		return this->charMinus(obj.d);
	else
		return 0;
}
var var::operator-=(var& obj)
{
	return *this = *this - obj;
}

var var::operator*(var& obj)
{
	//������ ������
	if (this->idVar == Null && obj.idVar == Int)
		return 0;
	else if (this->idVar == Null && obj.idVar == Double)
		return 0;
	else if (this->idVar == Null && obj.idVar == Char)
		return 0;
	//INT ������
	else if (this->idVar == Int && obj.idVar == Int)
		return this->i * obj.i;
	else if (this->idVar == Int && obj.idVar == Double)
		return this->i * static_cast<int>(obj.d);
	else if (this->idVar == Int && obj.idVar == Char)
		return this->i * obj.charToInt();
	////Double ������
	else if (this->idVar == Double && obj.idVar == Double)
		return this->d * obj.d;
	else if (this->idVar == Double && obj.idVar == Int)
		return this->d * static_cast<double>(obj.i);
	else if (this->idVar == Double && obj.idVar == Char)
		return this->d * obj.charToDouble();
	////�har ������
	else if (this->idVar == Char && obj.idVar == Char)
		return this->charMult(obj.c);
	else if (this->idVar == Char && obj.idVar == Int)
		return this->charMult(obj.i);
	else if (this->idVar == Char && obj.idVar == Double)
		return this->charMult(obj.d);
	else
		return 0;
}
var var::operator*=(var& obj)
{
	return *this = *this * obj;
}
var var::operator/(var& obj)
{
	//������ ������
	if (this->idVar == Null && obj.idVar == Int)
		return 0;
	else if (this->idVar == Null && obj.idVar == Double)
		return 0;
	else if (this->idVar == Null && obj.idVar == Char)
		return 0;
	//INT ������
	else if (this->idVar == Int && obj.idVar == Int)
		return this->i / obj.i;
	else if (this->idVar == Int && obj.idVar == Double)
		return this->i / static_cast<int>(obj.d);
	else if (this->idVar == Int && obj.idVar == Char)
		return this->i / obj.charToInt();
	////Double ������
	else if (this->idVar == Double && obj.idVar == Double)
		return this->d / obj.d;
	else if (this->idVar == Double && obj.idVar == Int)
		return this->d / static_cast<double>(obj.i);
	else if (this->idVar == Double && obj.idVar == Char)
		return this->d / obj.charToDouble();
	////�har ������
	else if (this->idVar == Char && obj.idVar == Char)
		return this->charDiv(obj.c);
	//else if (this->idVar == Char && obj.idVar == Int)
	//	return this->charMult(obj.i);
	//else if (this->idVar == Char && obj.idVar == Double)
	//	return this->charMult(obj.d);
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
//������������ ���� � ���
char* var::toChar(int n)
{
	char* temp = new char[20];
	snprintf(temp, 20, "%d", n);
	return temp;
}
//������������ ���� � ���
char* var::toChar(double n)
{
	char* temp = new char[20];
	snprintf(temp, 20, "%f", n);
	return temp;
}
//������ ��������� ���
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
		char* ch = toChar(obj.i);
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
		char* ch = toChar(obj.d);
		
		size_t length = strlen(this->c) + strlen(ch);
		char* temp = new char[length];
		for (int i{}; i < strlen(this->c); i++)
			temp[i] = this->c[i];

		for (int i{}; i < strlen(ch) + 1; i++)
			temp[strlen(this->c) + i] = ch[i];

		return temp;
	}
	else
		return 0;


}
//������ �������� ���
char* var::charMinus(var obj)
{
	if (obj.idVar == Char)
	{
		size_t lengthThis = strlen(this->c);
		size_t lengthobj = strlen(obj.c)+1;
		
		//�������� �������� �������
		size_t countOverlap{};

		//���� ����������� ��������� �������
		for (size_t i{}; i < lengthobj; i++)
		{
			for (size_t j{}; j < lengthThis; j++)
				if (this->c[j] == obj.c[i])
				{
					countOverlap++;
					i++;
				}
		}

		char* tempCopy = new char[lengthThis];
		char* temp = new char[lengthThis - countOverlap];

		//���������
		for (int i{}; i < lengthThis; i++)
			tempCopy[i] = this->c[i];

		//��������� ��������� ������� ��������� ��
		for (int i{}; i < lengthobj; i++)
		{
			for (int j{}; j < lengthThis; j++)
			{
				if (tempCopy[j] == obj.c[i])
				{
					tempCopy[j] = 0;
					i++;
				}
			}
		}
		//��������� � ������� 0 �������
		for (int i{}, j{}; i < lengthThis; i++)
		{
			if (tempCopy[i] != 0)
			{
				temp[j] = tempCopy[i];
				j++;
			}

		}
		delete[] tempCopy;
		//��������� � ����� ������ ���� �������
		temp[lengthThis - countOverlap] = '\0';

		return temp;
	}
	else if (obj.idVar == Int)
	{
		size_t lengthThis = strlen(this->c);
		char* ch = toChar(obj.i);
		size_t lengthobj = strlen(ch)+1;

		//�������� �������� �������
		size_t countOverlap{};

		//���� ����������� ��������� �������
		for (size_t i{}; i < lengthobj; i++)
		{
			for (size_t j{}; j < lengthThis; j++)
				if (this->c[j] == ch[i])
				{
					countOverlap++;
					i++;
				}
		}

		char* tempCopy = new char[lengthThis];
		char* temp = new char[lengthThis - countOverlap];

		//���������
		for (int i{}; i < lengthThis; i++)
			tempCopy[i] = this->c[i];

		//��������� ��������� ������� ��������� ��
		for (int i{}; i < lengthobj; i++)
		{
			for (int j{}; j < lengthThis; j++)
			{
				if (tempCopy[j] == ch[i])
				{
					tempCopy[j] = 0;
					i++;
				}
			}
		}
		//��������� � ������� 0 �������
		for (int i{}, j{}; i < lengthThis; i++)
		{
			if (tempCopy[i] != 0)
			{
				temp[j] = tempCopy[i];
				j++;
			}

		}
		delete[] tempCopy;
		//��������� � ����� ������ ���� �������
		temp[lengthThis - countOverlap] = '\0';

		return temp;
	}
	else if (obj.idVar == Double)
	{
	size_t lengthThis = strlen(this->c);
	char* ch = toChar(obj.d);
	size_t lengthobj = strlen(ch) + 1;

	//�������� �������� �������
	size_t countOverlap{};

	//���� ����������� ��������� �������
	for (size_t i{}; i < lengthobj; i++)
	{
		for (size_t j{}; j < lengthThis; j++)
			if (this->c[j] == ch[i])
			{
				countOverlap++;
				i++;
			}
	}

	char* tempCopy = new char[lengthThis];
	char* temp = new char[lengthThis - countOverlap];

	//���������
	for (int i{}; i < lengthThis; i++)
		tempCopy[i] = this->c[i];

	//��������� ��������� ������� ��������� ��
	for (int i{}; i < lengthobj; i++)
	{
		for (int j{}; j < lengthThis; j++)
		{
			if (tempCopy[j] == ch[i])
			{
				tempCopy[j] = 0;
				i++;
			}
		}
	}
	//��������� � ������� 0 �������
	for (int i{}, j{}; i < lengthThis; i++)
	{
		if (tempCopy[i] != 0)
		{
			temp[j] = tempCopy[i];
			j++;
		}

	}
	delete[] tempCopy;
	//��������� � ����� ������ ���� �������
	temp[lengthThis - countOverlap] = '\0';

	return temp;
	}
	else 
		return 0;

}

//������ �������� ���
char* var::charMult(var obj)
{
	if (obj.idVar == Char)
	{
		//����� ������ ������ ��������� �������
		int sizeCount{};
		///ϳ�������� ��������� ������� �� ����� �������� �������
		for (int i{}; i < strlen(this->c); i++)
		{
			for (int j{}; j < strlen(obj.c); j++)
			{
				if (this->c[i] == obj.c[j])
				{
					sizeCount++;
				}
			}
		}

		char* copythis = new char[sizeCount];

		for (int i{}; i < sizeCount;)
		{
			for (int j{}; j < strlen(this->c); j++)
			{
				for (int k{}; k < strlen(obj.c); k++)
				{
					if (this->c[j] == obj.c[k])
					{
						copythis[i] = this->c[j];
						i++;
					}
				}
			}
		}
		//��������� � ����� ������ ���� �������
		copythis[sizeCount] = '\0';
		return copythis;
	}
	else if (obj.idVar == Int)
	{
		char* ch = toChar(obj.i);
		//����� ������ ������ ��������� �������
		int sizeCount{};
		///ϳ�������� ��������� ������� �� ����� �������� �������
		for (int i{}; i < strlen(this->c); i++)
		{
			for (int j{}; j < strlen(ch); j++)
			{
				if (this->c[i] == ch[j])
				{
					sizeCount++;
				}
			}
		}

		char* copythis = new char[sizeCount];

		for (int i{}; i < sizeCount;)
		{
			for (int j{}; j < strlen(this->c); j++)
			{
				for (int k{}; k < strlen(ch); k++)
				{
					if (this->c[j] == ch[k])
					{
						copythis[i] = this->c[j];
						i++;
					}
				}
			}
		}
		//��������� � ����� ������ ���� �������
		copythis[sizeCount] = '\0';
		delete[] ch;
		return copythis;


	}
	else if (obj.idVar == Double)
	{
		char* ch = toChar(obj.d);
		//����� ������ ������ ��������� �������
		int sizeCount{};
		///ϳ�������� ��������� ������� �� ����� �������� �������
		for (int i{}; i < strlen(this->c); i++)
		{
			for (int j{}; j < strlen(ch); j++)
			{
				if (this->c[i] == ch[j])
				{
					sizeCount++;
				}
			}
		}

		char* copythis = new char[sizeCount];

		for (int i{}; i < sizeCount;)
		{
			for (int j{}; j < strlen(this->c); j++)
			{
				for (int k{}; k < strlen(ch); k++)
				{
					if (this->c[j] == ch[k])
					{
						copythis[i] = this->c[j];
						i++;
					}
				}
			}
		}
		//��������� � ����� ������ ���� �������
		copythis[sizeCount] = '\0';
		delete[] ch;
		return copythis;


	}
	else
	return 0;
}

//������ / ���
char* var::charDiv(var obj)
{
	if (obj.idVar == Char)
	{
		//����� ������ ������ ��������� �������
		int sizeCount{};
		
		///ϳ�������� ����� ������� �� ����� �������� �������
		for (int i{}; i < strlen(this->c); i++)
		{
			for (int j{}, k{}; j < strlen(obj.c); j++)
			{
				if (this->c[i] != obj.c[j])
				{
					k++;
				}
				
				if (k == strlen(obj.c))
				{
					sizeCount++;
					k = 0;
				}
			}
		}
		
		//std::cout << sizeCount << " this is sizeCount\n";

		char* copythis = new char[sizeCount];

		//��������� ������� � 1 ������ �� �� ���� � ������� 2 
		for (int i{}; i < sizeCount; i++)
		{
			for (int j{},l{}; j < strlen(this->c); j++, l=0)
			{
				for (int k{}; k < strlen(obj.c); k++)
				{
					if (this->c[j] != obj.c[k])
					{
						l++;
					}


					if (l == strlen(obj.c))
					{
						copythis[i] = this->c[j];
						l = 0;
						i++;

					}
				}
			}
		}


		//��������� � ����� ������ ���� �������
		copythis[sizeCount] = '\0';
		return copythis;
	}
	else if (obj.idVar == Int)
	{
		char* ch = toChar(obj.i);
		//����� ������ ������ ��������� �������
		int sizeCount{};
		///ϳ�������� ��������� ������� �� ����� �������� �������
		for (int i{}; i < strlen(this->c); i++)
		{
			for (int j{}; j < strlen(ch); j++)
			{
				if (this->c[i] == ch[j])
				{
					sizeCount++;
				}
			}
		}

		char* copythis = new char[sizeCount];

		for (int i{}; i < sizeCount;)
		{
			for (int j{}; j < strlen(this->c); j++)
			{
				for (int k{}; k < strlen(ch); k++)
				{
					if (this->c[j] == ch[k])
					{
						copythis[i] = this->c[j];
						i++;
					}
				}
			}
		}
		//��������� � ����� ������ ���� �������
		copythis[sizeCount] = '\0';
		delete[] ch;
		return copythis;


	}
	else if (obj.idVar == Double)
	{
		char* ch = toChar(obj.d);
		//����� ������ ������ ��������� �������
		int sizeCount{};
		///ϳ�������� ��������� ������� �� ����� �������� �������
		for (int i{}; i < strlen(this->c); i++)
		{
			for (int j{}; j < strlen(ch); j++)
			{
				if (this->c[i] == ch[j])
				{
					sizeCount++;
				}
			}
		}

		char* copythis = new char[sizeCount];

		for (int i{}; i < sizeCount;)
		{
			for (int j{}; j < strlen(this->c); j++)
			{
				for (int k{}; k < strlen(ch); k++)
				{
					if (this->c[j] == ch[k])
					{
						copythis[i] = this->c[j];
						i++;
					}
				}
			}
		}
		//��������� � ����� ������ ���� �������
		copythis[sizeCount] = '\0';
		delete[] ch;
		return copythis;


	}
}