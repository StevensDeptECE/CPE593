#include <iostream>
using namespace std;

template<typename T>
class LinkedList {
private:
	class Node {
	public:
		T v;
		Node* next;
		Node(T v, Node* n) : v(v), next(n) {}
	};
	Node* head;  // LinkedList<T>::Node
public:
  LinkedList() : head(nullptr) {}
	~LinkedList() {
		for (Node* p = head; p != nullptr; ) {
			Node* q = p;
			p = p->next;
			delete q;
		}
	}
  LinkedList(const LinkedList& orig) {
		if (orig.head == nullptr) {
			head = nullptr;
			return;
		}
		head = new Node(orig.head->v, nullptr);
		Node*q = head;
		for (Node* p = orig.head->next; p != nullptr; p = p->next, q = q->next) {
      q->next = new Node(p->v, nullptr);
		}
	}

	LinkedList& operator =(const LinkedList& orig) {
		LinkedList copy(orig); // calls copy constructor
		swap(head, copy.head);
		return *this;
	}

  void addEnd(const T& v) {
		if (head == nullptr) {
			head = new Node(v, nullptr);
			return;
		}
		Node* p;
		for(p = head; p->next != nullptr; p= p->next)
			;
		p->next = new Node(v, nullptr);
	}

	void addStart(const T& v) {
		head = new Node(v, head);
	}
	void removeEnd() {
		if (head == nullptr)
			return;
		if (head->next == nullptr) {
			delete head;
			head = nullptr;
			return;
		}
		Node* p;
		Node* q;
		for (p = head, q = p->next; q->next != nullptr; p = q, q = q ->next)
			;
		delete q;
		p->next = nullptr;
	}
	void removeStart(){
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	friend ostream& operator <<(ostream& s, const LinkedList& list) {
		for (Node* p = list.head; p != nullptr; p = p->next)
			s << p->v;
		return s;
	}
};

class Point {
public:
	double x, y;
	Point(double x, double y){}
};
int main() {
	// a = 9876543210
	LinkedList<Point> a;
	Point p(1,2);
	a.addStart(p);
	cout << a;
	LinkedList<Point> b = a;
	cout << a;
	
}
	
