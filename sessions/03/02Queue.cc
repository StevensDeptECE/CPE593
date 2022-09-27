class Queue {
private:
	LinkedList2 impl; // head and tail pointer only, singly linked
public:
	void enqueue(int v) { //O(1)
		impl.addEnd(v);
	}

	int dequeue() {
		return impl.removeStart(); // O(1)
	}

	bool isEmpty() const {
	  return impl.isEmpty();
	}
};

// using a dynamic array does not work, add/remove from start is too slow
class Queue2 {
private:
	DynArray impl; // head and tail pointer only, singly linked
public:
	void enqueue(int v) { //O(1)
		impl.addEnd(v);
	}

	int dequeue() {
		return impl.removeStart(); // O(n)
	}

	bool isEmpty() const {
	  return impl.isEmpty();
	}
};

class CircularBuffer {
private:
	int* buffer;
	uint32_t capacity;
  uint32_t head, tail;
public:
	CircularBuffer(uint32_t capacity) : capacity(capacity) {
		buffer =new int[capacity];
		head = 0;
		tail = 0;
	}
	~CircularBuffer(){}
	
	void enqueue(int v) {
		buffer[tail] = v;
		tail = (tail + 1) % capacity;
		if (head == tail) {
			grow();
		}
	}

	int dequeue() {
		int v = buffer[head];
		head = (head + 1) % capacity;
		return v;
	}
	bool isEmpty() const {
		return head == tail;
	}
};


int main() {
	Queue q;
	q.enqueue(3); // add to the END of the queue
	int v = q.dequeue(); // remove from the FRONT
}
