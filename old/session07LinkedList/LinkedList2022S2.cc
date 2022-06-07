#include <iostream>
using namespace std;

class LinkedList {
private:
	struct Node {
	public:
    // by default, PRIVATE

		int val; // 4 bytes padding
		Node* next;
		Node(int v, Node* p) : val(v), next(p) {}
	};

	Node* head;
public:
	LinkedList() {
    head = nullptr;    
	}
	~LinkedList() {
		Node* temp;
		for (Node* p = head; p != nullptr;) {
			temp = p;
			p = p->next;
			delete temp;
		}
	}
		// copy constructor
	LinkedList(const LinkedList& orig) {
		if (orig.head == nullptr) {
			head = nullptr;
			return;
		}
		head = new Node(orig.head->val, nullptr);
		Node*last = head;
		
		for (Node* p = orig.head; p != nullptr; p = p->next) {
			last->next = new Node(p->val, nullptr);
			last = last->next;
		}
	}

	LinkedList& operator=(const LinkedList& orig) = delete;

	void addStart(int v) {
		head = new Node(v, head);
	}
	
	void addEnd(int v) {
		if (head == nullptr) {
			head = new Node(v, nullptr);
			return;
		}
		
    Node* p;
		for (p = head; p->next != nullptr; p = p->next)
			;
		p->next = new Node(v, nullptr);
	}
	void removeStart() {
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	void removeEnd() {

	}
	friend ostream& operator <<(ostream& s, const LinkedList& list) {
		for (Node* p = list.head; p != nullptr; p = p->next)
			s << p->val << ' ';
		return s;
	}
};

void f() {
	LinkedList a;
	for (int i = 0; i < 10; i++)
		a.addStart(i);
	LinkedList b = a;
}
int main() {
	LinkedList a; // create an empty LinkedList
	LinkedList b(); // b is a FUNCTION that returns LinkedList

	a.addEnd(3);
	for (int i = 0; i < 10; i++)
		a.addStart(i);
	for (int i = 0; i < 10; i++)
		a.addEnd(i);
	//	b.addStart(3);
	a.removeStart();
	a.removeEnd();
	cout << a << '\n';
	LinkedList copy(a);
	LinkedList copy2 = a; // copy constructor
}
