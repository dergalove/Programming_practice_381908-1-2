#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Octal {
private:

	unsigned char* n;
	int size;
	
public:

	int input();

	Octal();

	Octal(int x);

	Octal(const Octal& b);

	~Octal();

	Octal operator+(Octal& a) const;

	Octal operator-(Octal& a) const;

	Octal operator==(Octal& a);

	//friend istream& operator>>(istream&, Octal&);

	//friend ostream& operator<<(ostream&, const Octal&);
};
