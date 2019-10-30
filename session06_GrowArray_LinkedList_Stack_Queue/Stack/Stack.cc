#include <iostream>
using namespace std;

class Stack {
private:
	LinkedList1 impl; // head only, one direction
public:
	void push(int v) { // O(1)
		impl.addStart(v); // O(1)
	}
	int pop() { //O(1)
		return impl.removeStart();
	}
	int top() const { //O(1)
		return impl.start();
	}
	bool isEmpty() const { // O(1)
		return impl.isEmpty();
	}
};
