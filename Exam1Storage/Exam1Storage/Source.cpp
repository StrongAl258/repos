#include <iostream>
using namespace std;
class Storage {
	int *hold;
public:
	Storage(int h = 0) {
		hold = new int(h);
		cout << endl << "constructor (Storage): Holding " << h;
	}
	~Storage() {
		cout << endl << "destructor (Storage): Releasing " << *hold;
		delete hold;
	}
	Storage(const Storage &source) {
		hold = new int(*source.hold);
		cout << endl << "copy constructor (Storage): Holding " << *hold;
	}
	Storage& operator= (const Storage& right) {
		cout << endl << "operator= (Storage): Releasing " << *hold;
		delete hold;
		hold = new int(*right.hold);
		cout << endl << "operator= (Storage): Holding " << *hold;
	}
	int& operator()() const {
		cout << endl << "operator() (Storage)";
		return *hold;
	}
};

class Array {
	Storage* array;
	int size;
public:
	Array(int* a, int length) {
		cout << endl << "constructor (Array)";
		array = new Storage[length];
		for (int i = 0; i < length; i++) {
			array[i]() = a[i];
		}
		size = length;
	}
	int& operator[] (int i) const {
		cout << endl << "operator[] (Array)";
		return array[i]();
	}
	~Array() {
		cout << endl << "destructor (Array)";
		delete[] array;
	}
};

int main() {
	int myArray[] = { 3615, 4629 };
	int length = sizeof(myArray) / sizeof(int);
	Array myObject(myArray, length);
	for (int i = 0; i < length; i++)
		cout << endl << myObject[i];
	return 0;
}