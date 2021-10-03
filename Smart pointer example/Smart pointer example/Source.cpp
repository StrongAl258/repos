#include <iostream>
#include <memory>
#include <exception>
#include <stdexcept>

void doSomething() {
	//int* a = new int{ 10000000 };    //instead of using new and delete we're gonna use the see next line
	//std::unique_ptr<int> a{ new int(10000000) };
	//std::unique_ptr<int> a{ std::make_unique<int>(10000000) };
	std::shared_ptr<int> a{ std::make_shared<int>(10000000) };
	std::shared_ptr<int> b{ a };
	std::shared_ptr<int> c{ a };
	std::cout << *a << '\n';

	//delete a;
}

int main() {
	while (1) {
		doSomething();
	}
}

