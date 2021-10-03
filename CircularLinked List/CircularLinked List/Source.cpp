#include <iostream>
using namespace std;

typedef string Elem;
class CNode {
private:
	Elem elem;
	CNode* next;
	friend class CircleList;
};

class CircleList {							// a circularly linked list
public:
	CircleList();							// constructor
	~CircleList();							// destructor
	bool empty() const;						// is list empty?
	const Elem& front() const;				// element at cursor
	const Elem& back() const;				// element following cursor
	void advance();							// advance cursor
	void add(const Elem& e);				// add after cursor
	void remove();							// remove node after cursor
private:
	CNode* cursor;							// the cursor
};

CircleList::CircleList() : cursor(NULL) {}	//constructor

CircleList::~CircleList()					// destructor
{ 
	while (!empty()) remove();
}

bool CircleList::empty() const				// is list empty?
{ 
	return cursor == NULL;
}

const Elem& CircleList::back() const		// element at cursor
{
	return cursor->elem;
}
const Elem& CircleList::front() const		// element following cursor
{
	return cursor->next->elem;
}
void CircleList::advance()					// advance cursor
{
	cursor = cursor->next;
}

void CircleList::add(const Elem& e) {		// add after cursor
	CNode* v = new CNode;					// create a new node
	v->elem = e;
	if (cursor == NULL) {					// list is empty?
		v->next = v;						// v points to itself
		cursor = v;							// cursor points to v
	}
	else {									// list is nonempty?
		v->next = cursor->next;				// link in v after cursor
		cursor->next = v;
	}
}

void CircleList::remove() {
	CNode* old = cursor->next;
	if (old == cursor)
		cursor = NULL;
	else
		cursor->next = old->next;
	delete old;
}

int main() {
	CircleList playList;
	playList.add("Stayin Alive");
	playList.add("Le Freak");
	playList.add("Jive Talkin");
	cout << playList.back() << endl;

	playList.advance();
	cout << playList.back() << endl;
	playList.advance();
	cout << playList.back() << endl;
	playList.remove();

	playList.add("Disco Inferno");
	playList.advance();
	cout << playList.back() << endl;

	return EXIT_SUCCESS;
}