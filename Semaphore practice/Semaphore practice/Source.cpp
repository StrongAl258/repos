// Alvin T Strong, Date: 17 Jun 2020
// Create a program with 3 readers 2 writers that all need to access the same critical area
// Ensure that only 2 readers or only 1 writer can be in the critical area at once time.
// If a breach of this condition happens output a "Panic Message"

#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

int pctr = 0;

