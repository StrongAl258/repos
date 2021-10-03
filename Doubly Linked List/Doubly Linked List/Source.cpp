#include <iostream>
using namespace std;
typedef string Elem;					// list element type
class DNode {						//doubly linked list node	
private:
	Elem elem;					// node element value
	DNode* prev;					// previous node in list
	DNode* next;					// next node in list
	friend class DLinkedList;			// allow DLinkedList access
};

class DLinkedList {
public:
	DLinkedList();
	~DLinkedList();
	bool empty() const;
	const Elem& front() const;
	const Elem& back() const;
	void addFront(const Elem& e);
	void addBack(const Elem& e);
	void removeFront();
	void removeBack();
	void print();
private:
	DNode* header;
	DNode* trailer;
protected:
	void add(DNode* v, const Elem& e);
	void remove(DNode* v);
};

DLinkedList::DLinkedList() {
	header = new DNode;
	trailer = new DNode;
	header->next = trailer;
	trailer->prev = header;
}

DLinkedList::~DLinkedList() {
	while (!empty()) removeFront();
	delete header;
	delete trailer;
}

bool DLinkedList::empty() const
{
	return (header->next == trailer);
}

const Elem& DLinkedList::front() const
{
	return header->next->elem;
}

const Elem& DLinkedList::back() const
{
	return trailer->prev->elem;
}

void DLinkedList::add(DNode* v, const Elem& e) {
	DNode* u = new DNode; 
	u->elem = e;
	u->next = v;
	u->prev = v->prev;
	v->prev->next = u;
	v->prev = u;
}

void DLinkedList::addFront(const Elem& e)
{
	add(header->next, e);
}

void DLinkedList::addBack(const Elem& e)
{
	add(trailer, e);
}

void DLinkedList::remove(DNode* v) {
	DNode* u = v->prev;
	DNode* w = v->next;
	u->next = w;
	w->prev = u;
	delete v;
}
void DLinkedList::removeFront()
{
	remove(header->next);
}

void DLinkedList::removeBack()
{
	remove(trailer->prev);
}
void DLinkedList::print() {
	DNode* v = header;
	while (v != trailer) {
		v = v->next;
		cout << v->elem << " ";
	}
}

int main() {
	DLinkedList a;
	a.addFront(" apple "); a.addFront(" apple "); a.addFront(" apple "); a.addFront(" apple "); a.addFront(" apple ");
	cout << a.front();
	a.print();

	return 0;
}