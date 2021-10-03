#include "Mixed.h"

Mixed::Mixed(int a, int b, int c) {
	if (((a == 0) && (c == 0)) ||
		(a < 0 && (b < 0 || c < 0)) ||
		(b < 0 && c < 0))
	{
		i = 0;
		n = 0;
		d = 0;
	}
	else {
		i = a;
		n = b;
		d = c;
	}
}
ostream& operator<<(ostream& out, const Mixed& x) 
{
	if (x.i != 0)
		out << x.i << " ";
	if (x.n == 0 || x.d == 0)
		if (x.i == 0)
			out << 0 << endl;
		else
			out << endl;
	else
		out << x.n << "/" << x.d << endl;
	return out;
}

istream& operator>>(istream& in, Mixed& x)
{
	int a, b, c;
	in >> a >> b >> c;
	if (((a == 0) && (c == 0)) ||
		(a < 0 && (b < 0 || c < 0)) ||
		(b < 0 && c < 0))
	{
		x.i = 0;
		x.n = 0;
		x.d = 0;
	}
	else {
		x.i = a;
		x.n = b;
		x.d = c;
	}
	return in;
}

double Mixed::Evaluate() {
	double a, b, c;
	a = i, b = n, c = d;
	
	if (a < 0.0)
		a--;
	if (a != 0 && b != 0)
		return a + b / c;
	else if (a == 0 && b != 0 && c != 0)
		return b / c;
	else if (a != 0 && (b == 0 || c == 0))
		return a;
}

void Mixed::ToFraction() {
	if (d > 0 && i != 0) {
		n = n + i * d;
	}
	else if (i != 0 && (n == 0 || d == 0))
	{
		n = i;
		d = 1;	
	}
	i = 0;
}
int Mixed::GCD(int a, int b) {
	if (a == 0 || b == 0)
		return 0;
	else if (a == b)
		return a;
	else if (a > b)
		return GCD(a - b, b);
	else return GCD(a, b - a);
}
void Mixed::Simplify() {
	if (i != 0) {
		if (i < 0) {
			if (n > d)
				i = i - n / d;
		}
		else
			i = i + n / d;
	}
	else if (n > d)
		i = i + n / d;

	n = (n % d);
	int gf = GCD(n, d);
	if (gf != 0) {
		n = n / gf;
		d = d / gf;
	}
}

void Mixed::Print() {
	if (i != 0)
		cout << i << " ";
	if (n == 0 || d == 0)
		if (i == 0)
			cout << 0 << endl;
		else
			cout << endl;
	else
		cout << n << "/" << d << endl;
}

Mixed Mixed::operator+(const Mixed& x) {
	if (this->n != 0 && x.n != 0) {
		if (this->i != 0) {
			this->n = this->n + this->i * this->d;
			this->i = 0;
		}
		if (x.i != 0)
			this->n = (this->n * x.d) + ((x.i * x.d + x.n) * this->d);
		else
			this->n = (this->n * x.d) + (x.d * this->d);

		this->d = this->d * x.d;

		int gf = GCD(this->n, this->d);
		if (gf != 0) {
			this->n = this->n / gf;
			this->d = this->d / gf;
		}
		if (this->n > this->d)
			if (this->n > this->d) {
				this->i = this->i + (this->n / this->d);
				this->n = this->n % this->d;
			}
	}
	this->i = this->i + x.i;
	
	return *this;
}

Mixed Mixed::operator-(const Mixed& x) {
	if (this->n != 0 && x.n != 0) {
		if (this->i != 0) {
			this->n = this->n + this->i * this->d;
			this->i = 0;
		}
		if (x.i != 0)
			this->n = (this->n * x.d) - ((x.i * x.d + x.n) * this->d);
		else
			this->n = (this->n * x.d) - (x.d * this->d);

		this->d = this->d * x.d;
		int gf = GCD(this->n, this->d);
		if (gf != 0) {
			this->n = this->n / gf;
			this->d = this->d / gf;
		}
		if(this->n > this->d)
			if (this->n > this->d) {
				this->i = this->i + (this->n / this->d);
				this->n = this->n % this->d;
			}
	}
	else this->i = this->i - x.i;

	return *this;
}

Mixed Mixed::operator*(const Mixed& x) {
	if (i == 0)
		i = x.i;
	else if (i != 0 && x.i != 0)
		i = i * x.i;
		n = n * x.n;
		d = d * x.d;
	return *this;
}

Mixed Mixed::operator/(const Mixed& x) {
	if (i == 0)
		i = x.i;
	else if (i != 0 && x.i != 0) {
		n = d * i;
		n = n * x.d;
		d = d * x.n;
	}
	else {
		n = n * x.d;
		d = d * x.n;
	}
	int gf = GCD(n, d);
	if (gf != 0) {
		n = n / gf;
		d = d / gf;
	}
	return *this;
}

Mixed& Mixed::operator++() {
	i++;
	return *this;
}

Mixed Mixed::operator++(int) {
	Mixed temp = *this;
	++*this;
	return temp;
}
Mixed& Mixed::operator--() {
	i--;
	return *this;
}

Mixed Mixed::operator--(int) {
	Mixed temp = *this;
	--*this;
	return temp;
}


