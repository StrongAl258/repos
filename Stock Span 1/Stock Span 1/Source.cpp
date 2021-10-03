//Alvin T Strong, 21 June 2020
//Implement an Array based Stack to compute Linear time algorithm
//To compute span days

#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;


class SpanDays {
	enum {MaxDays = 100};
public:
	SpanDays(int days = MaxDays);		// constructor with default value
	~SpanDays();						// destructor
	int size() const;					// number of items in stack
	bool empty() const;					// is the stack empty?
	const int& top() const;				// return top of stack
	void push(const int& e);			// push element onto the stack
	void pop();							// pop the stack
private:
	int* S;							// array of pointers
	int numDays;						// holds the max size of stack
	int t;								// actual size of stack
};
SpanDays::SpanDays(int days) :
	S(new int[days]), numDays(days), t(-1) {}	 // constructor from capacity

int SpanDays::size() const{
	return (t + 1);								// number of items in the stack
}
bool SpanDays::empty() const{
	return (t < 0);								// is the stack empty?
}
												// return top of stack unless empty
const int& SpanDays::top() const{
	if (empty()) 
		cout << "Top of empty Stack";
	else 
		return S[t];
}
												//push element onto the stack
void SpanDays::push(const int& e) {
	if (size() == numDays) 
		cout << "Push to a full stack";
	S[++t] = e;
}
												// pop the stack unless empty
void SpanDays::pop() {
	if (empty()) 
		cout << "Pop from empty stack";
	else 
		--t;
}
											
void calculateSpan(double price[], int n, int Sp[]) // Calculate Span Days
{
	SpanDays sd;								// Create Stack Object
	sd.push(0);									// Push first element to Stack
	Sp[0] = 1;									// First element is always 1
	for (int i = 1; i < n; i++)
	{											//Calculate remaining Span Values
		//pop elements from stack while stack is not empty and top is smaller than
		// price[i]
		while (!sd.empty() && price[sd.top()] <= price[i])
			sd.pop();
		//if stack is empty price[i] is greater than all elements left of it
		//else price[i] is greater than elements after top of stack
		Sp[i] = (sd.empty()) ? (i + 1) : (i - sd.top());
		sd.push(1); //push this element to stack
	}
}

void printArray(int arr[], int n) // print span values
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << ", ";
}
SpanDays::~SpanDays() { // deconstructor for Stack
			delete[] S;
}

int main()
{// Stock values for AMD over the last 10 market days
	double price[] = { 54.23, 54.04, 54.55, 54.46, 54.68,
		53.50, 52.83, 57.44, 56.39, 52.97 };
	const int n = sizeof(price) / sizeof(price[0]);
	int Span[n];

	calculateSpan(price, n, Span); \
		cout << "AMD Span Days over last 10 Market Days: " << endl;
	printArray(Span, n);
	return 0;
}