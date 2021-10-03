#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

class Students {
protected:
	string FName;
	string LName;
	string Subject;
	string Grades;
public:
	Students() {}
	Students(string a, string b) {
		
		istringstream s2(b);
		string c;
		s2 >> c;
		Grades = s2.str();
	}
	virtual string getSubject() const{
		return Subject;
	};
	virtual int final() { return 0; }
	virtual double average() {
		double a = 0;
		return a;
	}
	virtual char letG() { return ' '; }
	virtual string firstN() { return FName; }
	virtual string lastN() { return LName; }
	virtual string summary() { return "string"; }

};

class English: public Students{
protected:
	int t[4];
public:
	English(Students* s) {
		istringstream g(Grades);
		
	}
	string getSubject() {
		return Subject;
	}
	char letG() {
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
	string firstN() const { return FName; }
	string lastN() const { return LName; }
	string summary() {
		string summary() {
			stringstream s;
			s << FName << " " << LName << right << setw(8) << final() << setw(8) << average() << setw(6) << letG();
			return s.str();
		}
	}
};

class History : public Students {
protected:
	int t[3];
public:
	History(Students* s) {
		istringstream g(Grades);
		string c;

		for (int i = 0; i = 3; i++)
		{
			g >> c;
			if (i > 0)
			t[i - 1] = stoi(c);
		}
	}
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
	char letG() {
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
	string firstN() const { return FName; }
	string lastN() const { return LName; }
	string summary() {
		stringstream s;
		s << FName << " " << LName << right << setw(8) << final() << setw(8) << average() << setw(6) << letG();
		return s.str();
	}
};

class Math : public Students {
protected:
	int t[8];
public:
	Math(Students* s) {
		istringstream g(Grades);
		string c;

		for (int i = 0; i = 8; i++)
		{
			g >> c;
			if (i > 0)
			t[i - 1] = stoi(c);
		}
	}

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
			tq = q[i] + tq;
		}
		return tq * .15 + t1 * .25 + t2 * .25 + fe * .35;
	}
	char letG() {
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
	string firstN() const { return FName; }
	string lastN() const { return LName; }
	string summary() {
		string summary() {
			stringstream s;
			s << FName << " " << LName << right << setw(8) << final() << setw(8) << average() << setw(6) << letG();
			return s.str();
		}
	}
};

