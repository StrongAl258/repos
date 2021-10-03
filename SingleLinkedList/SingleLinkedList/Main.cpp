#include <iostream>
using namespace std;

template <typename E>
class SNode { // a node in a list of strings
public:
	E elem;							// element value
	SNode<E>* next;					// next item in the list
};

template <typename E>
class SLinkedList {							// a linked list of strings
public:
	SLinkedList();							// empty list constructor
	~SLinkedList();							// destructor
	bool empty() const;						// is list empty?
	const E& front() const;					// get front element
	void addFront(const E& e);				// add to front of list
	void removeFront();						// remove front item of list
	void addBack(const E& e);				// add to back of list
	void removeBack();						// remove back item of list
	void insert(const E& value);			// add to list where item belongs
	void remove(const E& value);			// remove specific item 
	void print();
private:
	SNode<E>* head;							// pointer to the head of list
};

template <typename E>
SLinkedList<E>::SLinkedList() : head(NULL) {} // constructor

template <typename E>
SLinkedList<E>::~SLinkedList()				  // destructor
{
	while (!empty()) removeFront();
}

template <typename E>
bool SLinkedList<E>::empty() const			  // is list empty?
{
	return head == NULL;
}

template <typename E>
const E& SLinkedList<E>::front() const		 // return front element
{
	return head->elem;
}

template <typename E>
void SLinkedList<E>::addFront(const E& e) { // add to front of list
	SNode<E>* v = new SNode<E>;				// create new node
	v->elem = e;							// store data
	v->next = head;							// head now follows v
	head = v;								// v is now the head
}

template <typename E>
void SLinkedList<E>::removeFront() {		// remove front item
	SNode<E>* old = head;					// save current head
	head = old->next;						// skip over old head
	delete old;								// delete the old head
}

template <typename E>
void SLinkedList<E>::addBack(const E& e) {  // add to back of list
	SNode<E>* v = head;						// v points to head
	while (v->next != NULL)						// while loop to run until v points to last element in list
		v = v->next;						// v becomes next element in list 
	SNode<E>* n = new SNode<E>;				// create new node
	n->elem = e;									// n takes e's value 
	v->next = n;							// n is added to back of list
	n->next = NULL;							// n points to NULL
}

template <typename E>
void SLinkedList<E>::removeBack() {	// remove from back of list
	SNode<E>* current = NULL;		// current has value of NULL
	SNode<E>* v = head;				// v points to head
	while (v->next != NULL)			// run until v points to NULL
	{
		current = v;				// current holds the value of v  
		v = v->next;				// v becomes next element in the list	
	}								// after loop ends current is pointing to second to last item 
	current->next = NULL;			// removes the pointer to v and points current to NULL
	delete(v);						// deletes the node and value of v
	v = NULL;						// v given value of NULL
}

template <typename E>
void SLinkedList<E>::insert(const E& value) {	// insert in order 
	addFront(value);							// add value to front of list
	SNode<E>* v = head;							// make v point to head which is value
	SNode<E>* n;
	E temp;// create n as the item after v 
	while (v != NULL)
	{
		n = v->next;
		while (n != NULL)
		{
			if (v->elem > n->elem)
			{
				temp = v->elem;
				v->elem = n->elem;
				n->elem = temp;
			}
			n = n->next;
		}
		v = v->next;
	}
}

template <typename E>
void SLinkedList<E>::remove(const E& value) {	// remove specific node
	SNode<E>* v = head;							// v points to head
	SNode<E>* n;	
	while (v != NULL) {							// run until v points to NULL
		n = v->next;
		while (n != NULL)
		{
			if (n->elem == value) {
				v->next = n->next;
				delete(n);
				n = NULL;
				break;
			}
			else
			{
				v = v->next;
				n = n->next;
			}
		}
		break;
	}
	

}

template <typename E>
void SLinkedList<E>::print() {					// print the list
	SNode<E>* v = head;							// v points to head
	while (v != NULL)							// run until v points to NULL 
	{
		cout << v->elem << endl;						// extract v node
		v = v->next;							// point to next node
	}
}


int main() {
	SLinkedList<int> Num;						// create an object named Num for integer values
	cout << Num.empty() << endl;				// confirm Num is empty

	Num.addFront(10);							// add the number 10 to the first node
	Num.addFront(3);							// add the number 3 to the first node
	Num.addFront(1);
	Num.addFront(8);
	Num.addFront(5);
	Num.addFront(7);
	Num.addBack(2);							// add the number 11 to the last node
	
	Num.print();								// print the list

	Num.insert(9);								// add the number 9 to the correct sorted position

	Num.print();
	Num.removeFront();
	Num.removeBack();
	Num.remove(7);

	Num.print();

	SLinkedList<string> Str;
	Str.addFront("Giselle");
	Str.addFront("Florale");
	Str.addFront("Kristelle");
	Str.addFront("Alvin");
	Str.addFront("Kathleena");
	Str.addFront("Gordon");
	Str.addFront("Stephone");
	Str.addFront("Simon");
	Str.addBack("Michael");
	Str.addBack("Alvina");
	Str.print();
	Str.insert("Celia");
	Str.print();

	return 0;
}