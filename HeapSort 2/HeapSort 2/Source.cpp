#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class VectorCompleteTree {
private:
	vector<int> V;									// tree contents
public:
	typedef typename vector<int>::iterator Position;	// a position in the tree
protected:
	Position pos(int i)								// map an index to a position
	{
		return V.begin() + i;
	}
	int idx(const Position& p) const				// map a position to an index
	{
		return p - V.begin();
	}
public:
	VectorCompleteTree() : V(1) {}					// constructor
	~VectorCompleteTree() {
		while (!V.empty())
		{
			removeLast();
		}
		V.clear();
	}
	int size() const {
		return V.size() - 1;
	}					// number of  elements
	Position left(const Position& p) {				// get left child
		return pos(2 * idx(p));
	}
	Position right(const Position& p) {				// get right child
		return pos(2 * idx(p) + 1);
	}
	Position parent(const Position& p) {			// get parent
		return pos(idx(p) / 2);
	}
	bool hasLeft(const Position& p) const {			// does node have left child?
		return 2 * idx(p) <= size();
	}
	bool hasRight(const Position& p) const {		// does node have right child?
		return 2 * idx(p) + 1 <= size();
	}
	bool isRoot(const Position& p) const {			// is this the Root?
		return idx(p) == 1;
	}
	Position root() {								// get root position
		return pos(1);
	}
	Position last() {							    // get last node
		return pos(size());
	}
	void addLast(const int& e) {						// add node to last position
		V.push_back(e);
	}
	void removeLast() {								// remove last node
		V.pop_back();
	}
	void swap(const Position& p, const Position& q) {// swap two nodes contents
		int e = *q; *q = *p; *p = e;
	}
};

class HeapPriorityQueue {
public:
	int size() const;								// number of elements
	bool empty() const;								// is the queue empty?
	void insert(const int& e);						// insert element
	const int& min();									// minimum element
	void removeMin();								// remove minimum
private:
	VectorCompleteTree T;						// priority queue contents
	bool isLess(int, int);									// less-than comparator
	typedef typename VectorCompleteTree::Position Position; //shortcut for tree position

};

//number of elements
int HeapPriorityQueue::size() const {
	return T.size();
}

// is queue empty?
bool HeapPriorityQueue::empty() const {
	return size() == 0;
}

// minimum element
const int& HeapPriorityQueue::min() {
	return *(T.root());
}							// return reference to root element

						   // insert element
void HeapPriorityQueue::insert(const int& e) {
	T.addLast(e);									// add e to heap
	Position v = T.last();							// e's position
	while (!T.isRoot(v)) {							// up-heap bubbling
		Position u = T.parent(v);
		if (!isLess(*v, *u)) break;					// if v in order, we're done
		T.swap(v, u);								// else swap with parent
		v = u;
	}
}
bool HeapPriorityQueue::isLess(int a, int b) {
	return a < b;
}
// remove minimum
void HeapPriorityQueue::removeMin() {
	if (size() == 1)								// only one node?
		T.removeLast();								// remove it
	else {
		Position u = T.root();						// root position
		T.swap(u, T.last());						// swap last with root
		T.removeLast();								// remove last
		while (T.hasLeft(u)) {						// down-heap bubbling
			Position v = T.left(u);
			if (T.hasRight(u) && isLess(*(T.right(u)), *v))
				v = T.right(u);						// v is u's smaller child
			if (isLess(*v, *u)) {					// is u out of order?
				T.swap(u, v);						// then swap
				u = v;
			}
			else break;								// else we're done
		}
	}
}

int main() {
	srand(time(NULL));
	HeapPriorityQueue H;
	int a;
	for (int i = 1; i <= 50; i++) {
		a = rand() % 1000;
		H.insert(a);
	}
	for (int i = 1; i <= 50; i++) {
		cout << H.min() << " ";
		H.removeMin();
	}

}