#include <iostream>
using namespace std;
#include "Rational.h"

void main()
{
	Rational a(3), b(4,8), c(b), d, e;
	d = a + b;
	cout << b << " " << d;
	cin >> e;
	if (e > d)
	{
		Rational tmp = d;
		d = e;
		e = tmp;
	}
	system("pause");
}