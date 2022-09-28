#include <iostream>
using namespace std;

class LinkedList {
private:
	struct Node {
	public:
    // by default, PRIVATE

		int val; // 4 bytes padding
		Node* next;
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

	}
	LinkedList& operator=(const LinkedList& orig) = delete;

	void addStart(int v) {
    Node* t = new Node();
		t->val = v;
		t->next = head;
		head = t;
	}
	
	void addEnd(int v) {
		if (head == nullptr) {
			head = new Node();
			head->val = v;
			head->next = nullptr;
			return;
		}
		
    Node* p;
		for (p = head; p->next != nullptr; p = p->next)
			;
		Node* temp = new Node();
		p->next = temp;
		temp->next = nullptr;
		temp->val = v;
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
}
