#include <iostream>
using namespace std;

class CreateDestroy
{
public:
	CreateDestroy() { cout << "Constructor called, "; }
	~CreateDestroy() { cout << "Destructor called, "; }
};

int main() {
	CreateDestroy c1;
	CreateDestroy c2;
	return 0;

}
	