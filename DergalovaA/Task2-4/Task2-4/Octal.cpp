#include "Octal.h"
#include <cmath>

Octal::Octal()
{
	//size = 1;
	n = 0;
}

Octal::Octal(int in)
{
	n = in;
}

Octal::Octal (Octal& in)
{
	n = in.n;
}

Octal::~Octal()
{
}

Octal Octal::operator+(const Octal& c)
{
  int max, lmax = 0, flag = 0; // octal > 0
  int m = 0;
  Octal res, a, b;
  b.n = c.n;
  a.n = n;
  if (b.n > a.n)
	  max = b.n;
  else
	  max = a.n;
  while (max > 0)
  {
	  lmax++;
	  max /= 10;
  }
  if (b.n < 0 && a.n < 0 || b.n > 0 && a.n > 0)
  {
	  if (b.n < 0 && a.n < 0)
	  {
		  a.n *= -1;
		  b.n *= (-1);
		  flag = 1;
	  }
	  for (int i = lmax; i != 0; i--)
	  {
		  m *= 10;
		  int sum = a.n%10 + b.n%10;
		  if (sum > 7)
			  sum += 2;
		  m += sum;
		  a.n /= 10;
		  b.n /= 10;
	  }
	  if (flag != 0)
		  res.n *= -1;
  }
  else //a и b разных знаков
  {
	  int fa = 1, fb = 1; //if a or b <0, we should change a sign of all of numbers
	  if (a.n < 0) // b>0
	  {
		  fa = -1;
		  a.n *= -1;
		  if (a.n > b.n) //abs, it means that octal res'll not change its sign after the operation
			  flag = 1;
	  }
	  else //b<0 a>0
	  {
		  fb = -1;
		  b.n *= -1;
		  if (a.n < b.n) //abs, it means res'll change its sign
			  flag = 1;
	  }
	  for (int i = lmax; i != 0; i--)
	  {
		  m *= 10;
		  int sum = a.n%10*fa + b.n%10*fb;
		  if (sum > 7)
			  sum += 2;
		  if (sum < 0)
			  sum -= 2;
		  m += sum;
		  a.n /= 10;
		  b.n /= 10;
	  }
  }
  while (m > 0) //perevorot
  {
	  res.n = res.n * 10 + m % 10;
	  m /= 10;
  }
  if (flag != 0)
	  res.n *= -1;
	return res;
}
Octal Octal::operator-(const Octal& c)
{
	Octal res, a, b;
	int a10=0, b10=0, i=0; //a8 to a10
	int fa = 1, fb = 1; // signs
	a = *this;
	b.n = c.n;
	if (a.n < 0)
	{
		a.n *= -1;
		fa = -1;
	}
	if (b.n < 0)
	{
		b.n *= -1;
		fa = -1;
	}
	while (a.n > 0 || b.n > 0)
	{
		a10 += a.n % 10 * pow(8, i);
		b10 += b.n % 10 * pow(8, i);
		a.n /= 10;
		b.n /= 10;
		i++;
	}
	//octal to decimal
	a10 *= fa;
	b10 *= fb; //returning the signs
	int r = a10 - b10;
	i = 0;
	while (r > 0)
	{
		res.n += r % 8 * pow(10, i);
		r /= 8;
		i++;
	} //decimal to octal
	return res;
	//i believe there is not cheating
}

Octal &Octal::operator=(Octal& a)
{
	n = a.n;
  return *this;
}

Octal &Octal::operator=(int a)
{
	n = a;
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