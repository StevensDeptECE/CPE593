#include <iostream>
using namespace std;

class Queue {
private:
	LinkedList2 impl; // head only, one direction
public:
	void enqueue(int v) { // O(1)
		impl.addEnd(v); //O(1)
	}
	int dequeue() { // O(1)
		return impl.removeStart(); //O(1)
	}

	bool isEmpty() const { // 
    return impl.isEmpty();
	}
};
