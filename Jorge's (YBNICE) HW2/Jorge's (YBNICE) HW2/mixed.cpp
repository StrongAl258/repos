#include "mixed.h"
int function = 0;
using namespace std;

Mixed::Mixed() { //unneccesary if you create default constructor values
	number_1 = 0;
	number_2 = 0;
	number_3 = 1;

}
Mixed::Mixed(int x) {//unneccesary if you create default constructor values
	number_1 = x;
	number_2 = 0;
	number_3 = 1;
}
Mixed::Mixed(int a, int b, int c) {
	if (c == 0) {
		cout << "Invalid Input" << endl;
	}
	if (a == 0 && b < 0) {
		cout << "Invalid Input" << endl;
	}
	if (a > 0 && (b < 0 || c < 0)) {
		cout << "Invalid Input" << endl;
	}
	else {
		number_1 = a;
		number_2 = b;
		number_3 = c;
	}
}
int Mixed::gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}
//finding lowest common factor
void Mixed::lowest(int& den3, int& num3)
{

	int common_factor = gcd(num3, den3);


	den3 = den3 / common_factor;
	num3 = num3 / common_factor;
}
//adding fraactions
void Mixed::addFraction(int num1, int den1, int num2,
	int den2, int& num3, int& den3)
{

	den3 = gcd(den1, den2);


	den3 = (den1 * den2) / den3;


	num3 = (num1) * (den3 / den1) + (num2) * (den3 / den2);


	lowest(den3, num3);
}
//subtracting fractions I dont know what this exist for... you already have an operator- overload

void Mixed::addFraction2(int num1, int den1, int num2,
	int den2, int& num3, int& den3)
{

	den3 = gcd(den1, den2);


	den3 = (den1 * den2) / den3;


	num3 = (num2) * (den3 / den2) - (num1) * (den3 / den1);


	lowest(den3, num3);
}

Mixed Mixed:: operator+(const Mixed& m) {
	Mixed temp(0, 0, 1);
	int num, dem;
	int t1 = (m.number_1 * m.number_3) + m.number_2;
	int t2 = (this->number_1 * this->number_3) + this->number_2;
	addFraction(t1, m.number_3, t2, this->number_3, num, dem);
	int t3 = num / dem;
	int t4 = num % dem;
	temp.number_1 = t3;
	if (t4 != 0) {
		temp.number_2 = t4;
		temp.number_3 = dem;
	}

	return temp;

}
Mixed Mixed::Print() {
	Mixed temp(0, 0, 1);
	if (this->number_1 != 0) {
		cout << this->number_1;
		cout << " ";
	}
	if (this->number_2 != 0) {
		cout << this->number_2;
		cout << "/";
		cout << this->number_3 << endl;;
	}
	if (this->number_1 == 0 && this->number_2 == 0) {
		cout << 0;
	}
	return temp;
}
Mixed Mixed:: operator-(const Mixed& m) {
	Mixed temp(0, 0, 1);
	int num, dem;
	int t1 = (m.number_1 * m.number_3) + m.number_2;
	int t2 = (this->number_1 * this->number_3) + this->number_2;
	addFraction2(t1, m.number_3, t2, this->number_3, num, dem);
	int t3 = num / dem;
	int t4 = num % dem;
	temp.number_1 = t3;
	if (t4 != 0) {
		temp.number_2 = t4;
		temp.number_3 = dem;
	}

	return temp;

}
Mixed Mixed:: operator*(const Mixed& m) {
	Mixed temp(0, 0, 1);
	int num, dem;
	int t1 = (m.number_1 * m.number_3) + m.number_2;
	int t2 = (this->number_1 * this->number_3) + this->number_2;
	num = t1 * t2;
	dem = m.number_3 * this->number_3;
	int t3 = num / dem;
	int t4 = num % dem;

	temp.number_1 = t3;
	if (t4 != 0) {
		temp.number_2 = t4;
		temp.number_3 = dem;
	}
	return temp;

}

Mixed Mixed:: operator/(const Mixed& m) {
	Mixed temp(0, 0, 1);
	int num, dem;
	int t1 = (m.number_1 * m.number_3) + m.number_2;
	int t2 = (this->number_1 * this->number_3) + this->number_2;
	dem = t1 * this->number_3;
	num = t2 * m.number_3;
	int t3 = num / dem;
	int t4 = num % dem;

	temp.number_1 = t3;
	if (t4 != 0) {
		temp.number_2 = t4;
		temp.number_3 = dem;
	}
	return temp;

}

Mixed Mixed:: operator ++() {
	Mixed temp(0, 0, 1);
	temp.number_1 = ++this->number_1;
	temp.number_2 = this->number_2;
	temp.number_3 = this->number_3;
	return temp;
}
Mixed Mixed::operator ++(int) {
	Mixed temp(0, 0, 1);
	temp.number_1 = this->number_1++;
	temp.number_2 = this->number_2;
	temp.number_3 = this->number_3;
	return temp;
}


bool operator == (Mixed& m1, Mixed& m2) {
	bool result = false;
	int num, dem;
	int t1 = (m1.number_1 * m1.number_3) + m1.number_2;
	int t2 = (m2.number_1 * m2.number_3) + m2.number_2;
	float t3 = (float)(t1);
	float t4 = (float)(t2);
	float t5 = (float)(m1.number_3);
	float t6 = float(m2.number_3);

	float n1 = t3 / t5;
	float n2 = t4 / t6;
	result = (n1 == n2);
	return result;


}
bool operator != (Mixed& m1, Mixed& m2) {
	bool result = false;

	int num, dem;
	int t1 = (m1.number_1 * m1.number_3) + m1.number_2;
	int t2 = (m2.number_1 * m2.number_3) + m2.number_2;
	float t3 = (float)(t1);
	float t4 = (float)(t2);
	float t5 = (float)(m1.number_3);
	float t6 = float(m2.number_3);

	float n1 = t3 / t5;
	float n2 = t4 / t6;
	result = (n1 != n2);
	return result;


}
bool operator > (Mixed& m1, Mixed& m2) {
	bool result = false;

	int num, dem;
	int t1 = (m1.number_1 * m1.number_3) + m1.number_2;
	int t2 = (m2.number_1 * m2.number_3) + m2.number_2;
	float t3 = (float)(t1);
	float t4 = (float)(t2);
	float t5 = (float)(m1.number_3);
	float t6 = float(m2.number_3);

	float n1 = t3 / t5;
	float n2 = t4 / t6;
	result = (n1 > n2);
	return result;


}
bool operator < (Mixed& m1, Mixed& m2) {
	bool result = false;

	int num, dem;
	int t1 = (m1.number_1 * m1.number_3) + m1.number_2;
	int t2 = (m2.number_1 * m2.number_3) + m2.number_2;
	float t3 = (float)(t1);
	float t4 = (float)(t2);
	float t5 = (float)(m1.number_3);
	float t6 = float(m2.number_3);

	float n1 = t3 / t5;
	float n2 = t4 / t6;
	result = (n1 < n2);
	return result;


}
bool operator >= (Mixed& m1, Mixed& m2) {
	bool result = false;

	int num, dem;
	int t1 = (m1.number_1 * m1.number_3) + m1.number_2;
	int t2 = (m2.number_1 * m2.number_3) + m2.number_2;
	float t3 = (float)(t1);
	float t4 = (float)(t2);
	float t5 = (float)(m1.number_3);
	float t6 = float(m2.number_3);

	float n1 = t3 / t5;
	float n2 = t4 / t6;
	result = (n1 >= n2);
	return result;


}
bool operator <= (Mixed& m1, Mixed& m2) {
	bool result = false;

	int num, dem;
	int t1 = (m1.number_1 * m1.number_3) + m1.number_2;
	int t2 = (m2.number_1 * m2.number_3) + m2.number_2;
	float t3 = (float)(t1);
	float t4 = (float)(t2);
	float t5 = (float)(m1.number_3);
	float t6 = float(m2.number_3);

	float n1 = t3 / t5;
	float n2 = t4 / t6;
	result = (n1 <= n2);
	return result;


}
ostream& operator << (ostream& out, static const Mixed& c)
{
	if (function == 0) {
		if (c.number_1 != 0) {
			out << c.number_1;
			out << " ";
		}
		if (c.number_2 != 0) {
			out << c.number_2;
			out << "/";
			out << c.number_3;
		}
		return out;
	}
	if (function == 1) {
		out << (c.number_1 * c.number_3 + c.number_2);
		out << "/";
		out << c.number_3;
		function = 0;
		return out;
	}

	if (function == 2) {
		int a1 = (c.number_1 * c.number_3) + c.number_2;
		int d1 = a1 / c.number_3;
		int d2 = a1 % c.number_3;
		if (d1 != 0) {
			out << d1;
			out << " ";
		}
		if (d2 != 0) {
			out << d2;
			out << "/";
			out << c.number_3;
		}
		function = 0;
		return out;
	}
}
//ToFraction function
void Mixed::ToFraction() {
	function = 1;
}
double Mixed::Evaluate() {
	function = 3;
	float a = (float)(this->number_1);
	float b = (float)(this->number_2);
	float d = (float)(this->number_3);
	float e = (b / d) + a;
	return e;
}
//Simplify function
void Mixed::Simplify() {

	int a1 = (this->number_1 * this->number_3) + this->number_2;
	int d1 = a1 / this->number_3;
	int d2 = a1 % this->number_3;

	this->number_1 = d1;
	if (d2 != 0) {
		this->number_2 = d2;
	}
	else {
		this->number_2 = 0;

	}

	function = 2;
}