#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Student.hpp"
using namespace std;
int main() {
	string inf, outf, name, split, size, subject, grades;
	int count = 0;
	cout << "Enter the name of the file: \n";
	cin >> inf;
	ifstream stufile{ inf };
	getline(stufile, size);
	count = stoi(size);
	cout << count << endl;
	Students** ssArr = new Students*[count];
	
	if (stufile.is_open())
	{
		for (int i = 0; i < count; i++)
			{
			getline(stufile, name);
			getline(stufile, split);
			istringstream s2(split);
			string sub;
			s2 >> sub;
			grades = s2.str();
			if (sub == "English")
				ssArr[i] = new English(name, sub, grades);
			else if (sub == "History")
				ssArr[i] = new History(name, sub, grades);
			else if (sub == "Math")
				ssArr[i] = new Math(name, sub, grades);
			}
		stufile.close();
	}
	else { cout << "Unable to open file"; exit(1); }
	for (int i = 0; i < count; i++)
	{
		cout << summary(ssArr[i]) << endl;
	}
	cout << "Enter the name of the report: " << endl;
	cin >> outf;

	ofstream report(outf);
	if (report.is_open())
	{
		report << " Student Grade Summary\n";
		report << " ---------------------\n\n";
		report << " ENGLISH CLASS\n\n";
		report << " Student" << right << setw(39) << "Final" << setw(10) << "Final" << setw(10) << "Letter\n";
		report << " Name   " << right << setw(39) << "Exam " << setw(10) << "Avg " << setw(10) << "Grade\n";
		report << " ------------------------------------------------------------------\n";
		for (int i = 0; i < count; i++)
		{
			if (ssArr[i]->getSubject() == "English")
			{
				report << summary(ssArr[i]) << endl;
				cout << summary(ssArr[i]) << endl;
			}
		}
		report << "\n\n HISTORY CLASS\n\n";
		report << " Student" << right << setw(39) << "Final" << setw(10) << "Final" << setw(10) << "Letter\n";
		report << " Name   " << right << setw(39) << "Exam " << setw(10) << "Avg " << setw(10) << "Grade\n";
		report << " ------------------------------------------------------------------\n";
		for (int i = 0; i < count; i++)
		{
			string alpha[2];
			if (ssArr[i]->getSubject() == "History")
			{
				report << summary(ssArr[i]) << endl;
				cout << summary(ssArr[i]) << endl;
			}
		}
		report << "\n\n MATH CLASS\n\n";
		report << " Student" << right << setw(39) << "Final" << setw(10) << "Final" << setw(10) << "Letter\n";
		report << " Name   " << right << setw(39) << "Exam " << setw(10) << "Avg " << setw(10) << "Grade\n";
		report << " ------------------------------------------------------------------\n";
		for (int i = 0; i < count; i++)
		{
			if (ssArr[i]->getSubject() == "Math")
			{
				report << summary(ssArr[i]) << endl;
				cout << summary(ssArr[i]) << endl;
			}
		}
		report.close();
		for (int i = 0; i < count; i++)
		{
			delete ssArr[i];
		}
		delete[] ssArr;
	}
	else 
		cout << "Unable to open file"; exit(1); 

	return 0;
}