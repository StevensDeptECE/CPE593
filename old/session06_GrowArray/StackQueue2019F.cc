class Stack {
private:
	LinkedList<int> impl;
public:
	Stack() : impl() {}
	void push(int v) { //O(1)
		impl.addStart(v);
	}
	int pop() { //O(1)
		impl.removeStart();
	}
	bool isEmpty() { //O(1)
		return impl.isEmpty();
	}
};

class Queue {
private:
	LinkedList2 impl;
public:
	Queue() : impl() {}
	void enqueue(int v) {//O(1)
		impl.addEnd();
	}
	int dequeue() { //O(1)
		return impl.removeStart();
	}
	bool isEmpty() {
		return impl.isEmpty();
	}
	
};
