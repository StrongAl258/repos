#include <iostream>
using namespace std;
class CheckingAccount {
	int b;
	string actname;
public:
	CheckingAccount(string a, int d){
		actname = a;
		b = d;
	}
	void withdraw(int x) {
		b -= x;
	}
	void balance() {
		cout << "Account{" << actname << "]: $" << b << endl;
	}

};
class SavingsAccount {
private:
	string actname;
	int b = 0;
	double ir = 0;
public:
	SavingsAccount(string a, int d, double i){
		actname = a;
		b = d;
		ir = i;
	}
	void withdraw(int x) {
		b -= x;
	}
	void balance() {
		cout << "Account{" << actname << "]: $" << b << endl;
	}
	void interest() {
		b = b + (b * (ir / 100));
	}

};
int main() {
	CheckingAccount ca{ "ID1", 500 };       // account number, money deposited

	SavingsAccount  sa{ "ID2", 1500, 1.0 }; // account number, money deposited, interest rate
	ca.withdraw(100);

	ca.balance();       // Shows message: "Account[ID1]: $400"

	sa.withdraw(100);

	sa.balance();       // Shows message: "Account[ID2]: $1400"

	sa.interest();

	sa.balance();       // Shows message: "Account[ID2]: $1414"
}