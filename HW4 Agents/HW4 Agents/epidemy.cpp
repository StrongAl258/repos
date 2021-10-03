// epidemy.cpp
// compile with --std=c++14 flag
#include <vector>
#include <iostream>
#include <iomanip>
#include <random>
#include "agents.hpp"
using namespace std;

#define INFECTION_RATE  0.03
#define DEATH_RATE      0.045

int nSimDays = 90;
int nHealthy = 5;
int nInfected = 1;

void printPopulation(int state, const vector<Agent*>& population) {
    cout << setfill('0') << setw(3) << state << ": ";
    for (int i = 0; i < population.size(); ++i)
        cout << (i == 0 ? "" : ", ") << *(population[i]);
    cout << endl;
}

int main() {

    // Seed the random number engine
    random_device rd;
    uniform_real_distribution<> dist(0.0, 1.0);

    vector<Agent*> population;

    // Generate population of healthy people
    for (int i = 0; i < nHealthy; ++i)
        population.push_back(new Healthy());

    // Add some infected  people
    for (int i = 0; i < nInfected; ++i)
        population.push_back(new Infected());

    // Show population
    printPopulation(0, population);

    // Simulation cycle
    for (int s = 1; s <= nSimDays; ++s) {
        for (int i = 0; i < population.size(); ++i) {
            Agent* a = population[i];

            if (a->isDead()) // either dead or cured
                continue;

            // determine if a healthy agent will catch infection
            if (!(a->isInfected()) && dist(rd) < INFECTION_RATE) {
                population[i] = new Infected(s);
                delete a;
                continue;
            }

            if (a->isInfected()) {
                // cure if passed enough time
                if (a->isCured(s)) {
                    population[i] = new Cured((Infected*)a, s);
                    delete a;
                }
                else
                    // determine if infected agent is going to die
                    if (dist(rd) < DEATH_RATE) {
                        population[i] = new Dead((Infected*)a, s);
                        delete a;
                    }
            }
        }
        printPopulation(s, population);
    }

    // Clear population
    for (auto a : population) {
        delete a;
    }
    cout << endl;

    return 0;
}
