#include <iostream>
using namespace std;

class DoubleLinkedList2 {
private:
	class Node { // DoubleLinkedList2::Node
	public:
		int data;
		Node* next;
		Node* prev;
		Node(int v, Node* n, Node* p) : data(v), next(n), prev(p) {}
	};
	Node* head;
	Node* tail;
public:
	DoubleLinkedList2() : head(nullptr), tail(nullptr) {}
	~DoubleLinkedList2() {
    for (Node* p = head; p != nullptr; ) {
			Node* temp = p;
			p = p->next;
			delete temp;
		}
	}
	DoubleLinkedList2(const DoubleLinkedList2& orig) { //O(n)
		if (orig.head == nullptr) { // special case for empty lists
			head = tail = nullptr;
			return;
		}
		head = new Node(orig.head->data, nullptr, nullptr);
		if (orig.head == orig.tail) {
			tail = head;
			return;
		}
		// guaranteed: at least 2 elements
		Node* q = head;
		for (Node* p = orig.head->next; p != nullptr; p = p->next) {
			Node* temp = new Node(p->data, nullptr, q);
			q->next = temp;
			q = temp;
		}

	}
	DoubleLinkedList2& operator =(const DoubleLinkedList2& orig) {
		DoubleLinkedList2 copy(orig);
		swap(head, copy.head);
		swap(tail, copy.tail);
		return *this;
	}

	
	void addEnd(int v) { //O(1)
		Node* temp = new Node(v, nullptr, tail);
		if (tail == nullptr) {
			head = tail = temp;
		} else {
			tail->next = temp;
			tail = temp;
		}
	}
	void addStart(int v) { //O(1)
		Node* temp = new Node(v, head, nullptr);
		if (head == nullptr) {
			head = tail = temp;
		} else {
			head->prev = temp;
			head = temp;
		}
	}

	void removeStart() {
		if (head == nullptr)
			return;
		if (head == tail) {
      delete head;
			head = tail = nullptr;
			return;
		}
		Node* temp = head;
		head = head->next;
		head->prev = nullptr;
		delete temp;
	}

	bool isEmpty() {
		return head == nullptr;
	}
	
	void removeEnd() {
		if (tail == nullptr)
			return;
		if (head == tail) {
			delete head;
			head = tail = nullptr;
			return;
		}
		Node* secondToLast = tail->prev;
		delete tail;
		secondToLast->next = nullptr;

	}
  friend ostream& operator <<(ostream& s, const DoubleLinkedList2& list) {
    for (Node* p = list.head; p != nullptr; p = p->next)
			s << p->data << ' ';
		return s;
	}
	class Iterator {
	private:
		Node* current;
	public:
		Iterator(const DoubleLinkedList2& orig) : current(orig.head)  {}
		bool operator !() const { return current != nullptr;  }
		Iterator& operator ++() {
			current = current->next;
			return *this;
		}
    int operator *()const { return current->data; }
	};
};
void f(DoubleLinkedList2 copy) {
}
int main() {
	DoubleLinkedList2 list;
	list.addEnd(5);
	list.removeEnd();
	list.addStart(3);
	list.removeStart();
	for (int i = 0; i < 10; i++)
		list.addEnd(i);
	list.removeStart();
	list.removeEnd();
	cout << list << '\n';
	//explicit copy	DoubleLinkedList2 list2 = list1;
	DoubleLinkedList2 list3;
	list3 = list; // operator =
	f(list);
	for (DoubleLinkedList2::Iterator i = list; !i; ++i)
		cout << *i << ' ';
	cout << '\n';
}
