#include "parasite.h"
#include "animal.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int simulationSteps = 10;

int main() {

    // seed rng
    srand(time(NULL));

    // Create an animal with 30% immunity rate and 5 parasites
    Animal* animal = new Animal{ 0.3, 5 };

    cout << "Begin simulation: " << endl;
    for (int i = 1; i <= simulationSteps && animal->getParasiteNumber() > 0; i++) {
        cout << animal << endl;
        cout << "Step " << i << ": " << endl;

        // setup collection of dead parasites
        vector<Parasite*> dead;

        // simulate behavior of a parasite
        int pnum = animal->getParasiteNumber();
        for (int i = 0; i < pnum; i++) {
            Parasite* parasite = (*animal)[i];
            float immunity = animal->getImmunity();
            // check if the parasite is survived
            bool survived = parasite->survive(immunity);

            // if survied, try to repoduce
            if (survived) {
                Parasite* offspring = parasite->reproduce(immunity);
                if (offspring != NULL)
                    animal->addParasite(offspring);
                else
                    cout << "Parasite " << i << " cannot reproduce" << endl;
            }
            else { // otherwise destroy the parasite
                dead.push_back(parasite);
                cout << "Parasite " << i << " is dead: " << parasite << endl;
            }
        }

        // remove dead parasites from the animal
        animal->destroyParasites(dead);
        dead.clear();

        // update currect number of parasites in animal
        pnum = animal->getParasiteNumber();

        // If the number of parasites more than the threshold
        // then the animal is dead, and we end the simulation

        if (pnum >= MAX_PARASITE_POP)
            break;

        // Boost immunity by taking drugs
        animal->takeDrugs();
        cout << "Animal takes drugs" << endl;
    }
    cout << "End simulation: " << endl;
    cout << animal << endl;

    // Destroy animal object
    delete animal;

    return 0;
}
