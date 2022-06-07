class Stack {
private:
	GrowArray impl;
public:
	Stack() : impl(1000) {}
	void push(int v) { impl.addEnd(v); } // O(1)
	int pop() { return impl.removeEnd(); } // O(1)
	bool isEmpty() { return impl.size() == 0; } // O(1)
};


class Stack {
private:
	Linked impl;
public:
	Stack() : impl(1000) {}
	void push(int v) { impl.addStart(v); } // O(1)
	int pop() { return impl.removeStart(); } // O(1)
	bool isEmpty() { return impl.head == nullptr; } // O(1)
};

class Queue {
private:
  LinkedList2 impl; // must have  head and tail
public:
	void enqueue(int v) {
		impl.addEnd(v); // O(1)
	}
	int dequeue() {
		return impl.removeStart();
	}
	bool isEmpty() const {
		return impl.head == nullptr;
	}
};

class CircularBuffer {
	int* data;
	int capacity;
	int head, tail;

	void enqueue(int v) {
		data[tail] = v;
		tail = tail+1;
		if (tail >= capacity)
			tail = 0;
    if (head == tail) {
			GROW();
		}
	}
