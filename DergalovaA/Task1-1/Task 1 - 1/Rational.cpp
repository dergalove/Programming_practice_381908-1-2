#include "Rational.h"

Rational operator+(Rational& a, Rational& b)
{
	Rational res;
	res.n = a.n + b.n;
	if (a.m + b.m != 0) res.m = a.m + b.m;
	simplify(res);
	return res;
}
Rational operator-(Rational& a, Rational& b)
{
	Rational res;
	res.n = a.n - b.n;
	res.m = a.m - b.m;
	simplify(res);
	return res;
}
Rational operator*(Rational& a, Rational& b)
{
	Rational res;
	res.n = a.n * b.n;
	res.m = a.m * b.m;
	simplify(res);
	return res;
}
Rational operator/(Rational& a, Rational& b)
{
	Rational res;
	res.n = a.n / b.n;
	res.m = a.m / b.m;
	simplify(res);
	return res;
}

Rational simplify(Rational& a)
{
	int nod = NOD(a.n, a.m);
	a.n /= nod;
	a.m /= nod;
	if (a.n < 0 && a.m < 0 || a.n>0 && a.m < 0)
	{
		a.n *= -1;
		a.m *= -1;
	}
	return *this;
};
Rational inicialize(int a, int b)
{
	Rational res;
	res.n = a;
	res.m = b;
	simplify(res);
	return res;
}
void sravn(Rational& a, Rational& b)
{
	if ((a.n == b.n) && (a.m == b.m))
		cout << "A is equal to B" << endl;
	else
		cout << "A is not equal to B" << endl;
}

void input()
{
	Rational res;
	cout << "Enter numerator and denominator:" << endl;
	cin >> res.n >> res.m;
}

void output(Rational& a)
{
	cout << a.n << "/" << a.m << endl;
}