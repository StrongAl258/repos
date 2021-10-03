#include <iostream>
using namespace std;
int GCD(int a, int b) {
	if (a == 0 || b == 0)
		return 0;
	else if (a == b)
		return a;
	else if (a > b)
		return GCD(a - b, b);
	else return GCD(a, b - a);
}
int main() {
	int x, y;
	x = 143;
	y = 276;
	cout << GCD(x, y) << endl;
	return 0;

}