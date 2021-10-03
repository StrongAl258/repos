#include "parasite.h"

Parasite::Parasite() {
	rRate = RAND_NUM;
	Resistance = RAND_NUM;
}
Parasite::Parasite(float aReRate, float bResistance) {
	rRate = aReRate;
	Resistance = bResistance;
}
bool Parasite::survive(float im) {
	return Resistance > im;
}
float Parasite::getReproductionRate() const{
	return rRate;
}
float Parasite::getResistance() const {
	return Resistance;
}
Parasite* Parasite::reproduce(float im) {
	if (rRate > im)
		return this;
	else return NULL;
}
ostream& operator<<(ostream& o, Parasite* p) {
	
	o << p->getReproductionRate() * 100.00 << "% reproduction rate, and " << p->getResistance() * 100 << "% resistance.";
	return o;
}
