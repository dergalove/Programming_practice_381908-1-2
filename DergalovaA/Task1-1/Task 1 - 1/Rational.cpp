#include "Rational.h"

Rational Rational::operator+(Rational& a)
{
	Rational res;
	res.n += a.n;
	//if (a.m + res.m == 0) всё плохо, вырубай; else
	res.m += a.m;
	res.simplify();
	return res;
}
Rational Rational::operator-(Rational& a)
{
	Rational res;
	res.n -= a.n;
	//if (a.m - res.m == 0) всё плохо, вырубай; else
	res.m -= a.m;
	res.simplify();
	return res;
}
Rational Rational::operator*(Rational& a)
{
	Rational res;
	res.n *= a.n;
	//if (a.m == 0 || res.m == 0) всё плохо, вырубай; else
	res.m *= a.m;
	res.simplify();
	return res;
}
Rational Rational::operator/(Rational& a)
{
	Rational res;
	res.n /= a.n;
	//if (a.m == 0 || res.m == 0) всё плохо, вырубай; else
	res.m /= a.m;
	//simplify(res);
	res.simplify();
	return res;
}

void Rational::simplify()
{
	int nod = NOD(n, m);
	n /= nod;
	m /= nod;
	if (m < 0)
	{
		n *= -1;
		m *= -1;
	}
};

Rational &Rational::operator=(Rational& a)
{
	n = a.n;
	m = a.m;
	simplify();
	return *this;
}

bool Rational::operator==(const Rational& a)
{
	bool res;
	res = (n == a.n && m == a.m);
	return res;
}

bool Rational::operator!=(const Rational& a)
{
	bool res;
	res = !(n == a.n && m == a.m);
	return res;
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