class LinkedList2 {
private:
	class Node {
	public:
		int val;
		Node* prev;
		Node* next;
	};

	Node* head;
	Node* tail;
public:
	LinkedList2() : head(nullptr), tail(nullptr) {}

	void addFirst(int v) {



	}
	void addLast(int v) {

		
	}
	int removeFirst() {

	}

	bool isEmpty() const { //O(1)
		return head == nullptr;
	}

	int size() const { //O(n)
		int count = 0;
		for (Node* p = head; p != nullptr; p =  p->next)
			count++;
		return count;
	}
};



class Queue {
private:
	LinkedList2 impl;

public:
	Queue() : impl() {}

	void enqueue(int v) {

	}

	int dequeue() {

	}

	bool isEmpty() {
		return impl.head == nullptr; //O(1)
	}
	
