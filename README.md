# class_var

Завдання №2
Реалізувати клас var — «Універсальна змінна». 


Об’єкти екземпляри цього класу здатні зберігати в собі значення наступних типів: int, double, String (рядок — вже
готовий клас).
Наприклад:
void main()
{
 var a = 15;
 var b = "Hello";
Практичні завдання №9
1
 var c = 7.8;
 var d = "50";
 b = a + d;
 b.Show(); // Виведе 65
 if (a == b) cout << "Equal\n";
 else cout << "Not Equal\n";
}
Для класу var необхідно:
■ перевантажити арифметичні оператори: +, –, *, /, + =,
–=, * =, / = ;
■ і оператори порівняння: <, >, <=, > =, ==, ! = (Всі перевантаження здійснюються як функції-члени класу var).
В змінній типу var в будь-який момент часу може зберігатися тільки одне значення (або int, або double, або String).
Під час перевантаження операторів враховувати наступне: якщо в операції типи значень двох операндів
типу var різні, то необхідно приводити (конвертувати)
значення з другого операнда до типу значення першого
операнда і тільки після цього виконувати операцію. (При
цьому значення (і тип) другого операнда в самому об’єкті
var не змінюються)
Наприклад:
var a = 10, b = "120", c;
c = a + b;
c.Show(); //Виведе 130
c = b + a;
c.Show(); //Виведе "12010"
Практичні завдання №9
2
Для типу Рядок операція «*» повинна повертати новий
рядок, що складається тільки з символів першого рядка,
які є у другому рядку, наприклад:
var a = "Microsoft", b = "Windows", c;
c = a * b;
c.Show(); //Виведе "ioso"
Для типу Рядок операція «/» повинна повертати новий
рядок, що складається з символів першого рядка, яких
немає у другому рядку, наприклад:
var a = "Microsoft", b = "Windows", c;
c = a / b;
c.Show(); //Виведе "Mcrft"
Аналогічно для Рядків: * = і / =.
Додати в клас var перетворення до типів: int, double,
char*.