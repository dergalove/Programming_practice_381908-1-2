#include "Octal.h"

int max(int a, int b)
{
	if (a > b)
		return a;
	else return b;
}

int Octal::input()
{
	ofstream file;
	file.open("input.txt");
	Octal obj;
	int len;
	cin >> len;
	unsigned char* str;
	cin >> str;
	obj.size = len;
	for (int i = 0; i < len; i++)
		obj.n[i] = str[i];
	file.write((char*)&obj, sizeof(obj));
	//file.close;
	return 0;
}

Octal::Octal()
{
	for (int i = 0; i < size; i++)
	n[i] = { 0 };
}

Octal::Octal(int x)
{
	int s = 0;
	while (x != 0)
	{
		if (x % 10 > 7) throw "Octal, not (Demical)!";
		x /= 10;
		s++;
	}
	for (int i = 0; i < size; i++)
		n[i] = x % 10;
}

Octal::Octal(const Octal& b)
{
	for (int i = 0; i < b.size; i++)
		n[i] = b.n[i];
}

Octal::~Octal()
{
}

Octal Octal::operator+(Octal& a) const
{
	Octal res;
	for (int i = 0; i < max(size, a.size); i++)
	{
		res.n[i] = n[i] + a.n[i];
		while (res.n[i] > 7)
		{
			res.n[i + 1]++;
			res.n[i] -= 8;
		}
	}
	return res;
}
Octal Octal::operator-(Octal& a)  const
{
	Octal res;
	for (int i = 0; i < max(size, a.size); i++)
	{
		res.n[i] = n[i] - a.n[i];
		while (res.n[i] < 0)
		{
			res.n[i + 1]--;
			res.n[i] += 8;
		}
	}
	return res;
}

Octal Octal::operator==(Octal& a)
{
	if (size != a.size)
		return 0;
	int i = 0;
	while (n[i] == a.n[i])
		i++;
	if (i == 0) return 1;
	else return 0;
}

/*istream & operator>>(istream & in, Octal & a)
{
	int n;
	//
	Octal res;
	a = res;
	return in;
}

ostream & operator<<(ostream & out, const Octal & a)
{
	out << a.n << endl;
	return out;
}*/


