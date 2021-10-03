#include "animal.h"


Animal::Animal(float aimmunity, int anumPara) {
	immunity = aimmunity;
	for (int i = anumPara; i > 0; i--)
	{
		parasites.push_back(new Parasite());
	}
	for (Parasite* j : parasites)
	{
		cout << "Parasite is born with " << j << endl;
	}
	cout << "Animal object is created" << endl;
}
Parasite* Animal::operator[](int a) {
	if (a < parasites.size())
		return parasites[a];
	else return NULL;

}
float Animal::getImmunity() const{
	return immunity;
}
int Animal::getParasiteNumber() const{
	return parasites.size();
};
void Animal::takeDrugs() {
	if (immunity < 1.0)
	immunity = immunity + 0.1;
};
void Animal::addParasite(Parasite* a) {
	parasites.push_back(new Parasite());
	cout << "Parasite is born with "<< parasites.back()<< endl;
};
Animal::~Animal(){
	for (int i = parasites.size();  i > 0; i-- )
	{
		delete parasites[i-1];
	}
	parasites.clear();
	cout << "Animal object deleted";
}
void Animal::destroyParasites(const vector<Parasite*> &a) {
	if (a.size() > 0)
	{
		for (int i = 0; i < parasites.size(); i++)
		{
			for (int j = a.size(); j > 0; j--)
			{
				if (parasites[i] == a[j - 1])
				{
						delete parasites[i];
						parasites.erase(parasites.begin() + i);
				}	
			}
		}
	}
};
ostream& operator<<(ostream& o, const Animal* a) {
	o << "This animal has immnity rate: " << a->immunity * 100 << "% and " << a->parasites.size() << " parasites." ;
	return o;
}