#include <iostream>
using namespace std;
#include "Octal.h"


int main()
{
	ofstream file;
	file.open("input.txt");
	file.close();

	Octal A, B(143), C, D(B), E, F;
	A = 34;
	E = A+B;
	if (A > B)
	{
		C = A - B;
	}
	else
		C = B - A;
	cin >> A >> B >> C >> D >> E;
	cout << F;
	system("pause");
}