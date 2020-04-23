#include "Octal.h"
#include <cmath>

Octal::Octal()
{
	size = 1;
	n[0] = 0;
}

Octal::Octal(int in)
{
	size = 1;
	int i = 0;
	int in2 = in;
	while (in2 > 0)
	{
		i++;
		in2 /= 10;
		//length
	}
	while (i > 0)
	{
		n[i] = in % 10;
		in /= 10;
		i--;
		size++;
    }
}

Octal::Octal (Octal& in)
{
	int i = size = in.size;
	while (i > 0)
	{
		n[i] = in.n[i];
		i--;
	}

}

Octal::~Octal()
{
}

Octal &Octal::operator+(const Octal& c)
{
	Octal res;
	int i;
	if (size < c.size)
		i = res.size = c.size;
	else
		i = res.size = size;
	while (i > 0)
	{
		res.n[i] = n[i] + c.n[i];
		if (res.n[i] > 7)
		{
			res.n[i] -= 8;
			res.n[i + 1] ++;
		}

		i--;
	}


  return res;
}
Octal &Octal::operator-(const Octal& c)
{
	Octal res;
	int i;
	if (size < c.size)
		i = res.size = c.size;
	else
		i = res.size = size;
	while (i > 0)
	{
		res.n[i] = n[i] - c.n[i];
		if (res.n[i] < 0)
		{
			res.n[i] += 8;
			res.n[i + 1] --;
		}
		i--;
	}
	return res;
}

Octal &Octal::operator=(Octal& a)
{
	int i = size = a.size;
	while (i > 0)
	{
		n[i] = a.n[i];
		i--;
	}
  return *this;
}

Octal &Octal::operator=(int a)
{
	size = 1;
	int i = 0;
	int a2 = a;
	while (a2 > 0)
	{
		i++;
		a2 /= 10;
		//length
	}
	while (i > 0)
	{
		n[i] = a % 10;
		a /= 10;
		i--;
		size++;
	}
	return *this;
}

bool Octal::operator==(const Octal& a)
{
	return (n == a.n);
}

bool Octal::operator!=(const Octal& a)
{
	return (n != a.n);
}

bool Octal::operator>(const Octal & a)
{
	return n > a.n;
}

bool Octal::operator<(const Octal & a)
{
	return n < a.n;
}

istream & operator>>(istream & in, Octal & a)
{
  ofstream file;
  file.open("input.txt", ios::app);
  file << a.n << endl;
  file.close();
  return in;
}

ostream & operator<<(ostream & out, const Octal & a)
{
  ifstream file ("input.txt");
  string line;
  while (getline(file, line))
    cout << line << endl;
  file.close();
	return out;
}