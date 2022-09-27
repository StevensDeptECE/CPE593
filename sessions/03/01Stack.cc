class LinkedList {
private:
	Node* head;
public:
	void addStart(int v) { //O(1)
		head = new Node(v, head); //O(1)
	}
 	int removeStart() { //O(1)
		Node* temp = head;
		int val = temp->val;
		head = temp->next;
		delete temp;
		return val;
	}
	int getSize() { //O(n)
		//TODO: 
	}
	bool isEmpty() const {
		return head == nullptr;
	}
};

class Stack {
private:
	LinkedList impl;
public:
	void push(int v) {
		impl.addStart(v); // O(1)
	}

	int pop() { // O(1)
		return impl.removeStart(); // O(??)

	}

	bool isEmpty() const { //O(1)
    return impl.isEmpty();
	}
};


class Stack2 {
private:
	DynamicArray impl;
public:
	void push(int v) { // O(1)
		impl.addEnd(v);
	}

	int pop() { // O(1)
		return impl.removeEnd(); // O(1)

	}

	bool isEmpty() const { //O(1)
    return impl.isEmpty();
	}
};

int main() {
}
