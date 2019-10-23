#include <iostream>
using namespace std;

template<typename T>
class LinkedList {
private:
	class Node { // LinkedList2019S.Node
	public:
	  int val;
		Node* next;

		Node(int v, Node* n) : val(v), next(n) {}
	};

	Node* head;

public:
	LinkedList() {
		head = nullptr; //O(1)
	}
	void addStart(int v) { //O(1)
		head = new Node(v, head);
	}

	void addEnd(int v) {
		Node* temp = new Node(v, nullptr);
		Node* p;
		if (head == nullptr) {
			head = temp;
			return;
		}
		// invariant: head is not null, list has at least 1 element
		for (p = head; p->next != nullptr; p = p->next)
			;
		//  p is pointing to last element
		p->next = temp;
	}

	void insert(int pos, int v) { //O(n)
		Node* p = head;
		while (pos > 0) {
			p = p->next;
			pos--;
		}
		p->next = new Node(v, p->next);
	}

	int removeStart() {
		Node* temp = head;
		head = head->next;
		return temp->val;
	}

	int removeEnd() {
		Node* p = head;
		Node* q = p->next;
		if (q == nullptr) {
			int v = head->val;
			head = nullptr;
			return v;
		}
		
		for (; q->next != nullptr; p = q, q = q->next)
			;
		p->next = nullptr;
		return q->val;
	}

	friend ostream& operator <<(ostream& s, const LinkedList& list) {
		for (Node* p = list.head; p != nullptr; p = p->next)
			s << p->val << ' ';
		return s;
	}
};
	
int main() {
	LinkedList<int> a;
	for (int i = 0; i < 10; i++)
		a.addStart(i);
	for (int i = 0; i < 10; i++)
		a.addEnd(i);
	a.removeStart();
	a.removeEnd();
	cout << a << '\n';
	return 0;
}
