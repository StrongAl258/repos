#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

ofstream report("Report.txt");				// Create a report file for output

void R1();	// Reader 1
void R2();	// Reader 2
void R3();	// Reader 3
void W1();	// Writer 1
void W2();	// Writer 2
// r1pc, r2pc, r3pc - Reader 1/2/3 Program Counter, w1pc, w2pc - Writer 1/2 Program Counter 
int r1pc = 0, r2pc = 0, r3pc = 0, w1pc = 0, w2pc = 0;
// TR1/2/3 - Total Reader 1, 2, 3, TW1/2 - Total Writer 1, 2
int TR1 = 0, TR2 = 0, TR3 = 0, TW1 = 0, TW2 = 0;
// Counters used for count inside of functions 1 for both writers to share since they shouldnt run at the same time. 
int countw = 0, countr1 = 0, countr2 = 0, countr3 = 0; //And one for each reader 1, 2, 3 respectively

int critsec[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19}; // "buffer" set up as a critical section with default values

int item, in = 0, out = 0; // item to act as data placed into buffer. in - for writers position in "buffer", out - for readers position in "buffer"
bool S = 1, Q = 1; // S works to lock out writer or reader. Q also lockes out reader and prevents multiple readers.
int rc = 0;	// rc - read counter. 

int main() {
	srand(time(NULL));	// random number generator
	int i = 0;			// counter

	while (i < 3000)
	{
		int choice = rand() % 5; // generator a random number to select which process runs
		switch (choice) {
		case 0:	R1();
			break; 
		case 1:	R2();
			break;
		case 2:	R3();
			break;
		case 3: W1();
			break;
		case 4:	W2();
			break;
		}
		i++;
		if (((r1pc > 3 && r1pc > 9) && (w1pc > 3 && w1pc < 11)) ||				// Check if Reader/writer are in the Critical Section at the same time
			((r1pc > 3 && r1pc < 9) && (w2pc > 3 && w2pc < 11)) ||
			((r2pc > 3 && r2pc < 9) && (w1pc > 3 && w1pc < 11)) ||
			((r2pc > 3 && r2pc < 9) && (w2pc > 3 && w2pc < 11)) ||
			((r3pc > 3 && r3pc < 9) && (w1pc > 3 && w1pc < 11)) ||
			((r3pc > 3 && r3pc < 9) && (w2pc > 3 && w2pc < 11)))
			report << "Reader and Writer in Critical Section at the same time." << endl;
		if ((r1pc > 3 && r1pc < 9) && (r2pc > 3 && r2pc < 9) && (r3pc > 3 && r3pc < 9)) // Check if all three readers are in the Critical Section 
			report << "Too many Readers in the Critical Section" << endl;
		if ((w1pc > 3 && w1pc < 11) && (w2pc > 3 && w2pc < 11))					// Check if both writers are in the Critical Section
			report << "Too many Writers in Critical Section" << endl;
	}
	report << "Total Runs: \n";
	report << "Writer 1: " << TW1 << endl;
	report << "Writer 2: " << TW2 << endl;
	report << "Reading 1: " << TR1 << endl;
	report << "Reading 2: " << TR2 << endl;
	report << "Reading 3: " << TR3 << endl;

}

void W1() {		//Writer 1
	w1pc++;
	while(true) {
		switch (w1pc) {
		case 1: item = rand() % 10000; w1pc++;				// give item a random value 0 - 10000
			break;
		case 2: if (S == 1) w1pc++; in = in % 20;			//  If S is true continue, make sure in does not equal a number higher than 20
			break;
		case 3: S = 0; Q = 0; w1pc++;						// "lock" S so other writer cannot enter CritSec "Lock" Q So no Readers can enter CritSec  
			break;
		case 4: report << "\tWriter 1 Entering Critical Section." << endl; w1pc++; // notification of entry to NCS
			break;
		case 5:	critsec[in] = item; in++; w1pc++;		 // add item to array, increment in
			break;
		case 6: if (countw > 1000) w1pc++; else countw++; // spend time in critical section to ensure no one else can enter due to context switch
			break;
		case 7: in = in % 20; w1pc++;					// ensure, in, is not greater than 20
			break;
		case 8: item = rand() % 10000; w1pc++;			//give item a random value
			break;
		case 9: critsec[in] = item; in++; w1pc++;		// add another item to array
			break;
		case 10: S = 1; Q = 1; w1pc++;					// exit Critical Section
			break;
		case 11: report << "\tWriter 1 Entering Non-critical section." << endl; w1pc++; //Notification of entry to NCS
			break;
		case 12: in = in % 20; TW1++; w1pc++;	// ensure, in, is not greater than 20, increment Total Writer 2 count. 
			break;
		}
		if (w1pc == 13) {			//reset w2pc count 
			break;
		}
	}
	w1pc = 0;
}
void W2() {		//Writer 2
	w2pc++;				//Increment w2pc in order to get to next case
	while (true) {	
		switch (w2pc) {
		case 1: item = rand() % 10000; w2pc++;				// give item a random value 0 - 10000
			break;
		case 2: if (S == 1) w2pc++; in = in % 20;			//  If S is true continue, make sure in does not equal a number higher than 20
			break;
		case 3: S = 0; Q = 0; w2pc++;						// "lock" S so other writer cannot enter CritSec "Lock" Q So no Readers can enter CritSec 
			break;
		case 4: report << "\tWriter 2 Entering Critical Section." << endl; w2pc++; // notification of entry to CS
			break;
		case 5:	critsec[in] = item; in++; w2pc++;			// add item to array, increment in
			break;
		case 6: if (countw > 1000) w2pc++; else countw++;	// spend time in critical section to ensure no one else can enter due to context switch
			break;
		case 7: in = in % 20; w2pc++;						// ensure, in, is not greater than 20
			break;
		case 8: item = rand() % 10000; w2pc++;				//give item a random value
			break;
		case 9: critsec[in] = item; in++; w2pc++;			// add another item to array
			break;
		case 10: S = 1; Q = 1; w2pc++;						// exit Critical Section unlock For other writer and readers
			break;
		case 11:report << "\tWriter 2 Entering Non-critical section." << endl; w2pc++; //Notification of entry to NCS
			break;
		case 12: in = in % 20; TW2++; w2pc++;				// ensure, in, is not greater than 20, increment Total Writer 2 count. 
			break;
		}
		if (w2pc == 13) {									//reset w2pc counter
			break;
		}
	}
	w2pc = 0;
}
void R1() {			// Reader 1
	r1pc++;													// increment r1pc to go to next case.
	while (true) {
		switch (r1pc) {
		case 1: if (Q == 1) r1pc++;							// If Q == 0 wait
			break;
		case 2:; rc++; r1pc++; out = out % 20;				// readcounter increment. Ensure, out, is not greater than 20
			break;
		case 3:  if (rc == 1) S = 0; r1pc++;				// Lock out writers
			break;
		case 4: if (rc == 2) Q = 0; r1pc++;					// If read count reaches 2 lock out other readers.
			break;
		case 5: report << "Reader 1 entering Critical Section: " << critsec[out] << endl; out++; r1pc++;	// Notification of entry to CS
			break;
		case 6: if (countr2 > 1000) r1pc++; else countr2++; // Extra time in Critical Section to ensure no mistakes. 
			break;
		case 7: rc--; Q = 1; r1pc++;						// readcounter decrement. Q = 1 so other readers can enter
			break;
		case 8: if (rc == 0) S = 1; r1pc++;					// Exiting Critical Section, if read counter = 0 release lock on writer.
			break;
		case 9: report << "Reader 1 entering Non-Critical Section." << endl; r1pc++; // Notification of entry to NCS
			break;
		case 10: out = out % 20; TR1++; r1pc++;				// ensure, out, is not greater than 20
			break;
		}
		if (r1pc == 11) {									// reset r1pc counter
			break;
		}
	}
	r1pc = 0;												// reset r1pc counter
}
void R2() {			// Reader 2
	r2pc++;													// increment r2pc to go to next case.
	while (true) {
		switch (r2pc) {
		case 1: if (Q == 1) r2pc++;							// If Q == 0 wait
			break;
		case 2:; rc++; r2pc++; out = out % 20;				// readcounter increment. Ensure, out, is not greater than 20 
			break;
		case 3:  if (rc == 1) S = 0; r2pc++;				// Lock out writers
			break;
		case 4: if (rc == 2) Q = 0; r2pc++;					// If read count reaches 2 lock out other readers.
			break;
		case 5: report << "Reader 2 entering Critical Section: " << critsec[out] << endl; out++; r2pc++;	// Notification of entry to CS
			break;
		case 6: if (countr2 > 1000) r2pc++; else countr2++;	// Extra time in Critical Section to ensure no mistakes
			break;
		case 7: rc--; Q = 1; r2pc++;						// readcounter decrement. Q = 1 so other readers can enter
			break;
		case 8: if (rc == 0) S = 1; r2pc++;					// Exiting Critical Section, if read counter = 0 release lock on writer.
			break;
		case 9: report << "Reader 2 entering Non-Critical Section." << endl; r2pc++;	// Notification of entry to NCS
			break;
		case 10: out = out % 20; TR2++; r2pc++;				// ensure, out, is not greater than 20
			break;
		}
		if (r2pc == 11) {									// break while loop when process done
			break;
		}
	}
	r2pc = 0;												// reset r2pc counter
}
void R3() {					// Reader 3
	r3pc++;													// increment r2pc to go to next case.
	while (true) {
		switch (r3pc) {
		case 1: if (Q == 1) r3pc++;							// If Q == 0 wait
			break;
		case 2:; rc++; r3pc++; out = out % 20;				// readcounter increment. Ensure, out, is not greater than 20
			break;
		case 3:  if (rc == 1) S = 0; r3pc++;				// Lock out writers
			break;
		case 4: if (rc == 2) Q = 0; r3pc++;					// If read count reaches 2 lock out other readers.
			break;
		case 5: report << "Reader 3 entering Critical Section: " << critsec[out] << endl; out++; r3pc++;	// Notification of entry to CS
			break;
		case 6: if (countr2 > 1000) r3pc++; else countr2++;	// Extra time in Critical Section to ensure no mistakes
			break;
		case 7: rc--; Q = 1; r3pc++;						// readcounter decrement. Q = 1 so other readers can enter
			break;
		case 8: if (rc == 0) S = 1; r3pc++;					// Exiting Critical Section, if read counter = 0 release lock on writer.
			break;
		case 9: report << "Reader 3 entering Non-Critical Section." << endl; r3pc++;	// Notification of entry to NCS
			break;
		case 10: out = out % 20; TR3++; r3pc++;				// ensure, out, is not greater than 20
			break;
		}
		if (r3pc == 11) {									// break while loop when process done
			break;
		}
	}
	r3pc = 0;												// reset r3pc counter
}