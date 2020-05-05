#pragma once
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

class Octal {
private:

	unsigned char* n;
	int size;

public:

	Octal();

	Octal(int in);

	Octal(Octal& in);

	~Octal();

	Octal &operator+(const Octal& c);

	Octal &operator-(const Octal& c);

	Octal &operator=(Octal& a);

	Octal &operator=(int a);

	bool operator==(const Octal& a);

	bool operator!=(const Octal& a);

	bool operator>(const Octal & a);

	bool operator<(const Octal & a);

	friend istream& operator>>(istream&, Octal&);

	friend ostream& operator<<(ostream&, const Octal&);
};