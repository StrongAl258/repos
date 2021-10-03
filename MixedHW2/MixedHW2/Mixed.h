#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

class Mixed {
	int i;
	int d;
	int n;
public:
	Mixed(int a = 0, int b = 0, int c = 0);
	friend ostream& operator<<(ostream& out, const Mixed& x);
	friend istream& operator>>(istream& in, Mixed& x);
	double Evaluate();
	void ToFraction();
	void Simplify();
	void Print();
	int GCD(int, int);
	bool operator<(const Mixed& x)const {
		if (i < x.i)
			return true;
		else if (i == x.i && d == x.d)
			return n < x.n;
		else
			return false;
	}
	bool operator>(const Mixed& x) const {
		if (i > x.i)
			return true;
		else if (i == x.i && d == x.d)
			return n < x.n;
		else
			return false;
	}
	bool operator<=(const Mixed& x) const {
		if (i <= x.i)
			if (d >= x.d)
				if (n <= x.n)
					return true;
				else
					return false;
			else
				return false;
		else
			return false;
	}
	bool operator>=(const Mixed& x) const {
		if (i >= x.i)
			if (d <= x.d)
				if (n >= x.n)
					return true;
				else
					return false;
			else
				return false;
		else
			return false;
		return false;
	}
	bool operator==(const Mixed& x) const {
		if (i == x.i && n == x.n && d == x.d)
			return true;
		else 
			return false;
	}
	bool operator!=(const Mixed& x) const {
		if (i != x.i && (n != x.n && d != x.d))
			return true;
		else 
			return false;
	}
	Mixed operator+(const Mixed& x);
	Mixed operator-(const Mixed& x);
	Mixed operator*(const Mixed& x);
	Mixed operator/(const Mixed& x);
	Mixed& operator++();
	Mixed operator++(int);
	Mixed& operator--();
	Mixed operator--(int);
};
