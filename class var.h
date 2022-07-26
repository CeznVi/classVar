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
	//Метод додавання чар
	char* charPlus(var obj);
	//Метод віднімання чар
	char* charMinus(var obj);
	//Метод * чар
	char* charMult(var obj);
	//Метод / чар
	char* charDiv(var obj);
	//Метод перетворення Чар в Інт
	int charToInt();
	//Метод перетворення Чар в Дабл
	double charToDouble();
	//Метод перетворення ІНТ, ДАБЛ в ЧАР
	char* toChar(int n);
	char* toChar(double n);

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

	//Метод перевантаження операторів
	var operator+(var& obj);
	var operator+=(var& obj);
	var operator-(var& obj);
	var operator-=(var& obj);
	var operator*(var& obj);
	var operator*=(var& obj);
	var operator/(var& obj);

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
	idVar = WhatIsIt::Char;
	delete c;
	c = new char[strlen(a) + 1];
	strcpy_s(c, strlen(a) + 1, a);

}
//Метод перевантаження операторів
var var::operator+(var& obj)
{
	//пустий перший
	if (this->idVar == Null && obj.idVar == Int)
		return obj.i;
	else if (this->idVar == Null && obj.idVar == Double)
		return obj.d;
	else if (this->idVar == Null && obj.idVar == Char)
		return obj.c;
	//INT перший
	else if (this->idVar == Int && obj.idVar == Int)
		return this->i + obj.i;
	else if (this->idVar == Int && obj.idVar == Double)
		return this->i + static_cast<int>(obj.d);
	else if (this->idVar == Int && obj.idVar == Char)
		return this->i + obj.charToInt();
	//Double перший
	else if (this->idVar == Double && obj.idVar == Double)
		return this->d + obj.d;
	else if (this->idVar == Double && obj.idVar == Int)
		return this->d + static_cast<double>(obj.i);
	else if (this->idVar == Double && obj.idVar == Char)
		return this->d + obj.charToDouble();
	//Сhar перший
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
	//Var перший пустий, верне значення другого зі знаком "-", крім масивів чар
	if (this->idVar == Null && obj.idVar == Int)
		return -obj.i;
	else if (this->idVar == Null && obj.idVar == Double)
		return -obj.d;
	else if (this->idVar == Null && obj.idVar == Char)
		return obj.c;
	//INT перший
	else if (this->idVar == Int && obj.idVar == Int)
		return this->i - obj.i;
	else if (this->idVar == Int && obj.idVar == Double)
		return this->i - static_cast<int>(obj.d);
	else if (this->idVar == Int && obj.idVar == Char)
		return this->i - obj.charToInt();	
	//Double перший
	else if (this->idVar == Double && obj.idVar == Double)
		return this->d - obj.d;
	else if (this->idVar == Double && obj.idVar == Int)
		return this->d - static_cast<double>(obj.i);
	else if (this->idVar == Double && obj.idVar == Char)
		return this->d - obj.charToDouble();
	//Сhar перший 
	//коли різниця чар від чар (то від першого чару відкидаються схожі символи з чароб обдж)
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
	//пустий перший
	if (this->idVar == Null && obj.idVar == Int)
		return 0;
	else if (this->idVar == Null && obj.idVar == Double)
		return 0;
	else if (this->idVar == Null && obj.idVar == Char)
		return 0;
	//INT перший
	else if (this->idVar == Int && obj.idVar == Int)
		return this->i * obj.i;
	else if (this->idVar == Int && obj.idVar == Double)
		return this->i * static_cast<int>(obj.d);
	else if (this->idVar == Int && obj.idVar == Char)
		return this->i * obj.charToInt();
	////Double перший
	else if (this->idVar == Double && obj.idVar == Double)
		return this->d * obj.d;
	else if (this->idVar == Double && obj.idVar == Int)
		return this->d * static_cast<double>(obj.i);
	else if (this->idVar == Double && obj.idVar == Char)
		return this->d * obj.charToDouble();
	////Сhar перший
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
	//пустий перший
	if (this->idVar == Null && obj.idVar == Int)
		return 0;
	else if (this->idVar == Null && obj.idVar == Double)
		return 0;
	else if (this->idVar == Null && obj.idVar == Char)
		return 0;
	//INT перший
	else if (this->idVar == Int && obj.idVar == Int)
		return this->i / obj.i;
	else if (this->idVar == Int && obj.idVar == Double)
		return this->i / static_cast<int>(obj.d);
	else if (this->idVar == Int && obj.idVar == Char)
		return this->i / obj.charToInt();
	////Double перший
	else if (this->idVar == Double && obj.idVar == Double)
		return this->d / obj.d;
	else if (this->idVar == Double && obj.idVar == Int)
		return this->d / static_cast<double>(obj.i);
	else if (this->idVar == Double && obj.idVar == Char)
		return this->d / obj.charToDouble();
	////Сhar перший
	else if (this->idVar == Char && obj.idVar == Char)
		return this->charDiv(obj.c);
	//else if (this->idVar == Char && obj.idVar == Int)
	//	return this->charMult(obj.i);
	//else if (this->idVar == Char && obj.idVar == Double)
	//	return this->charMult(obj.d);
	else
		return 0;
}



//Перетворюємо Чар то Інт
int var::charToInt()
{
	if (idVar != Char)
		return 0;

	int temp = atoi(this->c);
	return temp;
}
//Перетворюємо Чар то Double
double var::charToDouble()
{
	if (idVar != Char)
		return 0;

	double temp = atof(this->c);
	return temp;
}
//Перетворееня інта в чар
char* var::toChar(int n)
{
	char* temp = new char[20];
	snprintf(temp, 20, "%d", n);
	return temp;
}
//Перетворееня дабл в чар
char* var::toChar(double n)
{
	char* temp = new char[20];
	snprintf(temp, 20, "%f", n);
	return temp;
}
//Методи додавання чар
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
//Методи віднімання чар
char* var::charMinus(var obj)
{
	if (obj.idVar == Char)
	{
		size_t lengthThis = strlen(this->c);
		size_t lengthobj = strlen(obj.c)+1;
		
		//лічильник однкових символів
		size_t countOverlap{};

		//цикл підрахування однакових символів
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

		//копіювання
		for (int i{}; i < lengthThis; i++)
			tempCopy[i] = this->c[i];

		//видалення однакових символів занулення їх
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
		//копіювання з ігнором 0 символу
		for (int i{}, j{}; i < lengthThis; i++)
		{
			if (tempCopy[i] != 0)
			{
				temp[j] = tempCopy[i];
				j++;
			}

		}
		delete[] tempCopy;
		//Додавання у кінець масиву нуль термінал
		temp[lengthThis - countOverlap] = '\0';

		return temp;
	}
	else if (obj.idVar == Int)
	{
		size_t lengthThis = strlen(this->c);
		char* ch = toChar(obj.i);
		size_t lengthobj = strlen(ch)+1;

		//лічильник однкових символів
		size_t countOverlap{};

		//цикл підрахування однакових символів
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

		//копіювання
		for (int i{}; i < lengthThis; i++)
			tempCopy[i] = this->c[i];

		//видалення однакових символів занулення їх
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
		//копіювання з ігнором 0 символу
		for (int i{}, j{}; i < lengthThis; i++)
		{
			if (tempCopy[i] != 0)
			{
				temp[j] = tempCopy[i];
				j++;
			}

		}
		delete[] tempCopy;
		//Додавання у кінець масиву нуль термінал
		temp[lengthThis - countOverlap] = '\0';

		return temp;
	}
	else if (obj.idVar == Double)
	{
	size_t lengthThis = strlen(this->c);
	char* ch = toChar(obj.d);
	size_t lengthobj = strlen(ch) + 1;

	//лічильник однкових символів
	size_t countOverlap{};

	//цикл підрахування однакових символів
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

	//копіювання
	for (int i{}; i < lengthThis; i++)
		tempCopy[i] = this->c[i];

	//видалення однакових символів занулення їх
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
	//копіювання з ігнором 0 символу
	for (int i{}, j{}; i < lengthThis; i++)
	{
		if (tempCopy[i] != 0)
		{
			temp[j] = tempCopy[i];
			j++;
		}

	}
	delete[] tempCopy;
	//Додавання у кінець масиву нуль термінал
	temp[lengthThis - countOverlap] = '\0';

	return temp;
	}
	else 
		return 0;

}

//Методи множення чар
char* var::charMult(var obj)
{
	if (obj.idVar == Char)
	{
		//змінна розміру масиву однакових символів
		int sizeCount{};
		///Підрахунок однакових символів між двома масивами символів
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
		//Додавання у кінець масиву нуль термінал
		copythis[sizeCount] = '\0';
		return copythis;
	}
	else if (obj.idVar == Int)
	{
		char* ch = toChar(obj.i);
		//змінна розміру масиву однакових символів
		int sizeCount{};
		///Підрахунок однакових символів між двома масивами символів
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
		//Додавання у кінець масиву нуль термінал
		copythis[sizeCount] = '\0';
		delete[] ch;
		return copythis;


	}
	else if (obj.idVar == Double)
	{
		char* ch = toChar(obj.d);
		//змінна розміру масиву однакових символів
		int sizeCount{};
		///Підрахунок однакових символів між двома масивами символів
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
		//Додавання у кінець масиву нуль термінал
		copythis[sizeCount] = '\0';
		delete[] ch;
		return copythis;


	}
	else
	return 0;
}

//Методи / чар
char* var::charDiv(var obj)
{
	if (obj.idVar == Char)
	{
		//змінна розміру масиву однакових символів
		int sizeCount{};
		
		///Підрахунок різних символів між двома масивами символів
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

		//копіювання символів з 1 масиву які не схожі з масивом 2 
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


		//Додавання у кінець масиву нуль термінал
		copythis[sizeCount] = '\0';
		return copythis;
	}
	else if (obj.idVar == Int)
	{
		char* ch = toChar(obj.i);
		//змінна розміру масиву однакових символів
		int sizeCount{};
		///Підрахунок однакових символів між двома масивами символів
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
		//Додавання у кінець масиву нуль термінал
		copythis[sizeCount] = '\0';
		delete[] ch;
		return copythis;


	}
	else if (obj.idVar == Double)
	{
		char* ch = toChar(obj.d);
		//змінна розміру масиву однакових символів
		int sizeCount{};
		///Підрахунок однакових символів між двома масивами символів
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
		//Додавання у кінець масиву нуль термінал
		copythis[sizeCount] = '\0';
		delete[] ch;
		return copythis;


	}
}