#include <iostream>
using namespace std;

class DLinkedList {
	class Node {
		int  v;
		Node* next;
		Node* prev;
 		Node(int v, Node* next, Node* prev) : v(v), next(next), prev(prev) {}
	};

	Node* head;
	Node* tail;
public:
 	DLinkedList() { //O(1)
		head = tail = nullptr;
	}
	~DLinkedList()  { //O(n )
		Node* temp;
		for (Node* p = head; p != nullptr; p=temp) {
			temp = p->next;
      delete p;
		}
	}
	void addFirst(int v) {
		if (head == null) {
			head = tail = new Node(v, nullptr, nullptr);
			return;
		}
		//head = new Node(v, head, nullptr)
		Node* temp = new Node();
		temp->v = v;
		temp->next = head;
		temp->prev = nullptr;
		head->prev = temp;
		head = temp;
	}
	void addLast(int v) {
		if (head == null) {
			head = tail = new Node(v, nullptr, nullptr);
			return;
		}
		tail->next = new Node(v, nullptr, tail);
		tail = tail->next;
	}
	void removeFirst() {
		if (head == nullptr)
			return;
		if (head->next == nullptr) {
      delete head;
			head = tail = nullptr;
			return;
		}
		Node temp = head;
		head = head.next;
		head.prev = nullptr;
		free(temp);
	}

	void removeLast() {
		if (tail == nullptr)
			return;
		if (head->next == nullptr) {
			delete head;
			head = tail = nullptr;
		}
		tail = tail.prev; // go back!!!
		delete tail->next;
		tail->next = nullptr;
	}
  int get(int i) {
		Node* p = head;
		for (; i > 0 && p != nullptr; i--, p = p->next)
			;
		if (p == nullptr)
			throw "Diediedie";
		return p->v;
	}

  insertAfter(Node* p, int v) {
		//		p->next =    new Node(v, p->next, p)
		Node* temp = new Node();
		Node* q = p->next;
		temp->v = v;
		temp->next = q;
		temp->prev = p;
		p->next = temp;
		q->prev = temp;
	}

	  insertBefore(Node* p, int v) {
			if (p->prev == nullptr) {
				head = new Node(v, p, nullptr);
				p->prev = head;
				return;
			}
			insertAfter(p->prev,v);
			
		
	}

