#include <iostream>
using namespace std;

typedef string Elem;
class CNode {
private:
	Elem elem;
	CNode* next;

	friend class CircleList;
};

class CircleList {
public:
	CircleList();
	~CircleList();
	bool empty() const;
	const Elem& front() const;
	const Elem& back() const;
	void advance();
	void add(const Elem& e);
	void remove();
private:
	CNode* cursor;
};