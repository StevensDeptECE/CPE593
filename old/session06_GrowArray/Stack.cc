class Stack {
private:
	GrowArray impl;
public:
	void push(int v) { //O(1)
		impl.addEnd(v); //O(1)
	}
	int pop() {
		return impl.removeEnd(); //O(1)
	}

	bool isEmpty() const {
		return impl.size() == 0
	}
};

class Queue {
private:
  GrowArray impl;
public:
  void enqueue(int v) { //O(n)
    impl.addStart(v);
	}
	int dequeue() { //O(1)
    return imple.removeStart();
	}
	bool isEmpty() const { //O(1)
		return impl.size() = 0;
	}
}
