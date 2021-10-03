#ifndef ANIMAL_H
#define ANIMAL_H

#include "parasite.h"
#include <vector>
#include <iostream>
using namespace std;

class Animal{
	friend ostream& operator<<(ostream& o, const Animal* a);

	float immunity;
	vector<Parasite*> parasites;
public:
	Animal(float aImmunity, int aNumPara);
	~Animal();
	
	Parasite* operator[](int);

	float getImmunity() const;
	int getParasiteNumber() const;
	void addParasite(Parasite* a);
	void destroyParasites(const vector<Parasite*> &a);
	void takeDrugs();
};
#endif