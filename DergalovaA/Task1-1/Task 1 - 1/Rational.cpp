#include "Rational.h"


Rational::Rational()
{
	n = 0; m = 1;
}

Rational::Rational(int a, int b)
{
	if (b == 0) return;
	n = a; m = b;
	simplify();
}

Rational::Rational(int x)
{
	n = x; m = 1;
}

Rational::Rational(const Rational& b)
{
	n = b.n;
	m = b.m;
}

Rational::~Rational()
{
}

Rational Rational::operator+(Rational& a)
{
	Rational res;
	int tmp_m = m;
	if (m != a.m)
	{
		n *= a.m;
		m *= a.m;
		a.n *= tmp_m;
		a.m *= tmp_m;
	}
	res.n = n + a.n;
	res.m = m;
	a.m /= tmp_m;
	a.n /= tmp_m;
	simplify();
	return res;
}
Rational Rational::operator-(Rational& a)
{
	Rational res;
	int tmp_m = m;
	if (m != a.m)
	{
		n *= a.m;
		m *= a.m;
		a.n *= tmp_m;
		a.m *= tmp_m;
	}
	res.n = n - a.n;
	res.m = m;
	a.m /= tmp_m;
	a.n /= tmp_m;
	simplify();
	return res;
}
Rational Rational::operator*(Rational& a)
{
	n *= a.n;
	m *= a.m;
	simplify();
	return *this;
}
Rational Rational::operator/(Rational& a)
{
	n /= a.n;
	m /= a.m;
	simplify();
	return *this;
}

void Rational::simplify()
{
	if (m == 0) return;
	if (m < 0)
	{
		n *= -1;
		m *= -1;
	}
	int nod = NOD(n, m);
	n /= nod;
	m /= nod;
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

bool Rational::operator>(const Rational & a)
{
	return n * a.m > a.n * m;
}

bool Rational::operator<(const Rational & a)
{
	return n * a.m < a.n * m;
}

istream & operator>>(istream & in, Rational & a)
{
	int n, m;
	cin >> n >> m;
	Rational res(n, m);
	a = res;
	return in;
}

ostream & operator<<(ostream & out, const Rational & a)
{
	out << a.n << "/" << a.m << endl;
	return out;
}

