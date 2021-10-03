#include <iostream>
#include <array>
#include <exception>
#include <stdexcept>
using namespace std;

int main() {
	int a = 1 / 0;
	cout << a;
	return 0;
}