#pragma once
/* Разработать класс Rational(рациональное число).

Класс должен хранить корректные дроби n / m(знаменатель не равен 0).

Дробь должна храниться в несократимом виде.

Класс должен содержать все необходимые конструкторы и деструктор.

В классе должны быть перегружены операции:
присваивания
4 стандартные арифметические операции
сравнения
ввода / вывода в поток */

#include <iostream>
using namespace std;

int NOD(int n, int m)
{
	while (n != 0 && m != 0)
		if (n > m) n %= m; else n %= m;
	return n + m;
}

class Rational {

private:
	int n, m;

public:
	Rational plus(Rational& a, Rational& b);

	Rational minus(Rational& a, Rational& b); 

	Rational mult(Rational& a, Rational& b);

	Rational div(Rational& a, Rational& b);

	Rational simplify(Rational a);

	Rational inicialize(int a, int b);

	void sravn(Rational& a, Rational& b);

	void input();

	void output(Rational& a);
};