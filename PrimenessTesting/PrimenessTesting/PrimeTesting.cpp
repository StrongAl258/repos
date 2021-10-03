#include <iostream>
#include <cmath>

int rounddown(double x) {
	int y = pow(x, .5);
	return y;
}
int isPrime(int n) {
	for (int d = 2; d <= rounddown(n); d++)
	{
		if (n % d == 0)
		{
			return d;
		}
	}
	return 0;
}

int main() {
	int x;

	std::cout << "Enter a number to determine if it's a prime: " << std::endl;
	std::cin >> x;
	std::cout << isPrime(x) << std::endl;

	system("pause");
	return 0;
}