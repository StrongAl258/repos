#ifndef PARASITE_H
#define PARASITE_H

#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX_PARASITE_POP 100
#define RAND_NUM ((float)rand()/RAND_MAX)
class Parasite {
	friend ostream& operator<<(ostream& o, Parasite*);

	float Resistance;
	float rRate;
public:
	Parasite();
	Parasite(float aReRate, float bResistance);
	~Parasite() { };

	float getReproductionRate() const;
	float getResistance() const;
	Parasite* reproduce(float im);
	bool survive(float im);
};

#endif