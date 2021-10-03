#include <iostream>
using namespace std;

typedef int Elem;
class NodeList {
private:
	struct Node {
		Elem elem;
		Node* prev;
		Node* next;
	};
public:
	class Iterator {
	public:
		Elem& operator*();
		bool operator==(const Iterator& p) const;
		bool operator!=(const Iterator& p) const;
		Iterator& operator++();
		Iterator& operator--();
		friend class NodeList;
	private:
		Node* v;
		Iterator(Node* u);
	};
public:
	NodeList();
	NodeList(const NodeList& nl);
	~NodeList();
	int size() const;
	bool empty() const;
	Iterator begin() const;
	Iterator end() const;
	void insertFront(const Elem& e);
	void insertBack(const Elem& e);
	void insert(const Iterator& p, const Elem& e);
	void eraseFront();
	void eraseBack();
	void erase(const Iterator& p);
private:
	int n;
	Node* header;
	Node* trailer;
};

// Iterator Function Members
NodeList::Iterator::Iterator(Node* u) {
	v = u;
}
Elem& NodeList::Iterator::operator*() {
	return v->elem;
}
bool NodeList::Iterator::operator==(const Iterator& p) const {
	return v == p.v;
}
bool NodeList::Iterator::operator!=(const Iterator& p) const {
	return v != p.v;
}
NodeList::Iterator& NodeList::Iterator::operator++() {
	v = v->next; return *this;
}
NodeList::Iterator& NodeList::Iterator::operator--() {
	v = v->prev; return *this;
}

// NodeList Function Members
NodeList::NodeList() {
	n = 0;
	header = new Node;
	trailer = new Node;
	header->next = trailer;
	trailer->prev = header;
}
NodeList::NodeList(const NodeList& nl) {
	n = nl.n;
	header = new Node;
	trailer = new Node;
	if (n == 0)
	{
		header->next = trailer;
		trailer->prev = header;
	}
	else
	{
		Iterator p = nl.begin();
		while (p != nl.end()) {
			insertBack(*p);
			++p;
		}
	}
}
NodeList::~NodeList() {
	if (n != 0)
	{	
		Iterator p = begin();
		while (p != end()) {
			erase(p);
			p = begin();
		}
	}
	delete(header);
	delete(trailer);
}
int NodeList::size() const {
	return n;
}
bool NodeList::empty() const {
	return (n == 0);
}
NodeList::Iterator NodeList::begin() const {
	return Iterator(header->next);
}
NodeList::Iterator NodeList::end() const {
	return Iterator(trailer);
}
void NodeList::insert(const Iterator& p, const Elem& e) {
	Node* w = p.v;
	Node* u = w->prev;
	Node* v = new Node;
	v->elem = e;
	v->next = w; w->prev = v;
	v->prev = u; u->next = v;
	n++;
}
void NodeList::insertFront(const Elem& e) {
	insert(begin(), e);
}
void NodeList::insertBack(const Elem& e) {
	insert(end(), e);
}
void NodeList::erase(const Iterator& p) {
	Node* v = p.v;
	Node* w = v->next;
	Node* u = v->prev;
	u->next = w; w->prev = u;
	delete v;
	n--;
}
void NodeList::eraseFront() {
	erase(begin());
}
void NodeList::eraseBack() {
	erase(--end());
}

class NodeSequence : public NodeList {
public:
	Iterator atIndex(int i) const;
	int indexOf(const Iterator& p) const;
};
NodeSequence::Iterator NodeSequence::atIndex(int i) const {
	Iterator p = begin();
	for (int j = 0; j < i; j++) ++p;
	return p;
}
int NodeSequence::indexOf(const Iterator& p) const {
	Iterator q = begin();
	int j = 0;
	while (q != p) {
		++q; ++j;
	}
	return j;
}

void bubbleSort1(NodeSequence& S);
void bubbleSort2(NodeSequence& S);

int main() {
	NodeList n;
	n.insertFront(10);
	n.insertBack(5);
	NodeList::Iterator p(n.begin());
	cout << *p << " " << *++p << endl;
	n.insert(p, 8);
	n.insert(p, 3);
	n.insert(p, 2);
	n.insertBack(1);
	p = n.begin();
	while (p != n.end())
	{
		cout << *p << " ";
		++p;
	}
	cout << endl;
	NodeSequence b;
	p = n.begin();
	while (p != n.end()) {
		b.insertBack(*p);
		++p;
	}
	bubbleSort1(b);
	NodeSequence::Iterator pb(b.begin());
	while (pb != b.end())
	{
		cout << *pb << " ";
		++pb;
	}
	cout << endl;
	NodeSequence c;
	p = n.begin();
	while (p != n.end()) {
		c.insertBack(*p);
		++p;
	}
	bubbleSort2(c);
	NodeSequence::Iterator pc(c.begin());
	while (pc != c.end())
	{
		cout << *pc << " ";
		++pc;
	}

	return 0;
}
void bubbleSort1(NodeSequence& S){
	int n = S.size();
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n - i; j++) {
			NodeSequence::Iterator prec = S.atIndex(j - 1);
			NodeSequence::Iterator succ = S.atIndex(j);
			if (*prec > * succ) {
				int tmp = *prec; *prec = *succ; *succ = tmp;
			}
		}
	}
}
void bubbleSort2(NodeSequence& S){
	int n = S.size();
	for (int i = 0; i < n; i++) {
		NodeSequence::Iterator prec = S.begin();
		for (int j = 1; j < n - i; j++) {
			NodeSequence::Iterator succ = prec;
			++succ;
			if (*prec > * succ) {
				int tmp = *prec; *prec = *succ; *succ = tmp;
			}
			++prec;
		}
	}
}