#include "LinkedList2019S.cc"

class Stack {
private:
	LinkedList<int> impl;
	//	GrowArray impl; // would work with addEnd, removeEnd (addStart/removeStart is SLOW)
public:
	Stack() : impl() {}
	void push(int v) { // O(1)
		impl.addStart(v); //O(1)
	}

	int pop() { //O(1)
		return impl.removeStart(); // O(1)
	}

	bool isEmpty() {
		return impl.isEmpty();
	}
	
	int peek() const {
		return impl.getFirst();
	}
