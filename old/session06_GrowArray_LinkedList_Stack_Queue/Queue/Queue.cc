#include <iostream>
using namespace std;

class Queue {
private:
	LinkedList1 impl; // head only, one direction
public:
	void enqueue(int v) { // O(1)
		impl.addStart(v); //O(1)
	}
	int dequeue() { // O(n)
		return impl.removeEnd()
	}

	bool isEmpty() const { // 
    return impl.isEmpty();
	}
};
