
#include <iostream>
#include <algorithm>
using namespace std;

class Mixed {
public:
	int number_1 = 0;
	int number_2 = 0;
	int number_3 = 1;

public:
	Mixed();
	Mixed(int x);
	Mixed(int a, int b, int c); // can intiate default values in constructor
	void ToFraction();
	double Evaluate();
	void Simplify();
	int gcd(int a, int b);
	void lowest(int& den3, int& num3);
	void addFraction(int num1, int den1, int num2,
		int den2, int& num3, int& den3);
	void addFraction2(int num1, int den1, int num2,
		int den2, int& num3, int& den3);

	friend bool operator == (Mixed& m1, Mixed& m2);
	friend bool operator != (Mixed& m1, Mixed& m2);
	friend bool operator > (Mixed& m1, Mixed& m2);
	friend bool operator < (Mixed& m1, Mixed& m2);
	friend bool operator >= (Mixed& m1, Mixed& m2);
	friend bool operator <= (Mixed& m1, Mixed& m2);
	friend ostream& operator << (ostream& out, const Mixed& c);
	Mixed  operator+(const Mixed& m);

	Mixed Print();
	Mixed operator-(const Mixed& m);

	Mixed operator*(const Mixed& m);
	Mixed operator/(const Mixed& m);
	Mixed operator ++();
	Mixed operator ++(int);



};
