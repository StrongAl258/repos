#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

class Students {
protected:
public:
	virtual ~Students() {};
	virtual string getSubject() const = 0;
	virtual int final() const = 0;
	virtual double average() const = 0;
	virtual char letG() const = 0;
	virtual string getName() const = 0;
};
string summary(const Students* a) {
	stringstream s;
	s << left << setw(20) << a->getName() << right <<setw(24) << a->final() << setw(12) << fixed << setprecision(2) << a->average() << setw(8) << a->letG();
	return s.str();
}
class English: public Students{
protected:
	string Name, Subject;
	int t[4];
public:
	English(string a, string b, string c) {
		istringstream s1(a);
		string n[2];
		for (int i = 0; i < 2; i++)
		{
			getline(s1, n[i], ',');

		}
		Name = n[1] + " " + n[0];
		Subject = b;
		istringstream s(c);
		string d;
		for (int i = 0; i < 5; i++)
		{
			s >> d;
			if (i != 0)
			t[i-1] = stoi(d);
		}
	}
	string getName() const { return Name; }
	string getSubject() const{
		return Subject;
	}
	char letG() const{
		char a;
		int b = average();
		switch ( b / 10)
		{
		case 10:
		case 9: a = 'A';
			break;
		case 8: a = 'B';
			break;
		case 7: a = 'C';
			break;
		case 6: a = 'D';
			break;
		default: a = 'F';
		}
		return a;
	}
	int final() const{
		int a = t[3];
		return a;
	}
	double average() const{
		double a, b, c, d;
		a = t[0]; b = t[1]; c = t[2]; d = t[3];
		return a * 0.1 + b * 0.3 + c * 0.3 + d * 0.3;
	}
};

class History : public Students {
protected:
	string Name, Subject;
	int t[3];
public:
	History(string a, string b, string c) {
		istringstream s1(a);
		string n[2];
		for (int i = 0; i < 2; i++)
		{
			getline(s1, n[i], ',');

		}
		Name = n[1] + " " + n[0];
		Subject = b;
		istringstream s(c);
		string d;
		for (int i = 0; i < 4; i++)
		{
			s >> d;
			if (i != 0)
			t[i-1] = stoi(d);
		}
	}
	string getName()const { return Name; }
	string getSubject() const{
		return Subject;
	}
	int final() const{
		int a = t[2];
		return a;
	}
	double average() const{
		double a, b, c;
		a = t[0]; b = t[1]; c = t[2];
		return a * 0.25 + b * 0.35 + c * 0.4;
	}
	char letG() const{
		char a;
		int b = average();
		switch (b / 10)
		{
		case 10:
		case 9: a = 'A';
			break;
		case 8: a = 'B';
			break;
		case 7: a = 'C';
			break;
		case 6: a = 'D';
			break;
		default: a = 'F';
		}
		return a;
	}
};

class Math : public Students {
protected:
	string Name, Subject;
	int t[8];
public:
	Math(string a, string b, string c) {
		istringstream s1(a);
		string n[2];
		for (int i = 0; i < 2; i++)
		{
			getline(s1, n[i], ',');

		}
		Name = n[1] + " " + n[0];
		Subject = b;
		istringstream s(c);
		string d;
		for (int i = 0; i < 9; i++)
		{
			s >> d;
			if (i != 0)
			t[i - 1] = stoi(d);
		}
	}
	string getName()const { return Name; }
	string getSubject() const{
		return Subject;
	}
	int final() const{
		int a = t[7];
		return a;
	}
	double average() const{
		double tq = 0;
		double t1 = t[5];
		double t2 = t[6];
		double fe = t[7];
		double q[5];
		for (int i = 0; i < 5; i++)
		{
			q[i]= t[i];
			tq = q[i]*.2 + tq;
		}
		return tq * .15 + t1 * .25 + t2 * .25 + fe * .35;
	}
	char letG() const{
		char a;
		int b = average();
		switch (b / 10)
		{
		case 10:
		case 9: a = 'A';
			break;
		case 8: a = 'B';
			break;
		case 7: a = 'C';
			break;
		case 6: a = 'D';
			break;
		default: a = 'F';
		}
		return a;
	}
};

