//Alvin T Strong, 11 June 2020
//Project 1 Multi-Threading
//Create a program that Runs 2 threads, 
//one puts elements into an array and the other removes from the array
#include <iostream>
#include <windows.h>
#include <random>
using namespace std;
#define MAX_THREADS 2 
//array of handles
HANDLE hThreads[MAX_THREADS];
//array of thread ids
DWORD id[MAX_THREADS];
//a waiter so main doesnt close before threads end
DWORD waiter;
//in: for producer location in buffer array, out: for consumer location in buffer array
//item: holds random number value
int in = 0, out = 0, item = 0;
//BUFFER_SIZE: size of buffer array, counterLimit: length of while statement
int BUFFER_SIZE, counterLimit;
//So we can count each run of producer (countin) and consumer(countout)
int countin = 0, countout = 0;
//creation of array to act as buffer
int *buffer;
DWORD WINAPI producer(LPVOID n)//thread for elements going into "buffer"
{

	while (countin < counterLimit) {	
		//random number generator
		random_device rd;
		mt19937 mt(rd());
		uniform_int_distribution<int> dist(1, 100000);
		item = dist(mt); //gives item a random value
		while (((in + 1) % BUFFER_SIZE) == out)
			;//do nothing - no free buffers
		buffer[in] = item; //array assigned to buffer position
		cout << "Item #" << countin++ << " placed in buffer position "<< in << endl;
		in = (in + 1) % BUFFER_SIZE; //change the value of in to move to the next array element
	}
	return (DWORD)n;
}
DWORD WINAPI consumer(LPVOID n)//thread for elements coming out of "buffer"
{
	while (countout < counterLimit) {
		while (in == out)
			; //do nothing - nothing in buffer
		//print output and then remove an item from the buffer
		cout << "Item #"<< countout++ <<  " removed from buffer, is: " << buffer[out] << endl;
		out = (out + 1) % BUFFER_SIZE;
	}
	return (DWORD)n;
}

int main(int argc, char* argv[]) 
{


	//Get buffer size and Counter Limit
	cout << "Enter the Buffer Size then Counter Limit: ";
	cin >> BUFFER_SIZE >> counterLimit;
		
	buffer = new int[BUFFER_SIZE]; //Dynamic Array creation
	//create threads
	hThreads[0] = CreateThread(NULL, 0, producer, (LPVOID)0, NULL, &id[0]);
	hThreads[1] = CreateThread(NULL, 0, consumer, (LPVOID)0, NULL, &id[1]);
	//wait for the threads to finish before ending main
	waiter = WaitForMultipleObjects(MAX_THREADS, hThreads, TRUE, INFINITE);
	//close handles for threads
	for (int i = 0; i < MAX_THREADS; i++) {
		CloseHandle(hThreads[i]);
	}
	return 0;

}