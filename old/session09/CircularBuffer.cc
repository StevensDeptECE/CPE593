class CircularBuffer {
private:
	uint32_t* p;
	uint32_t capacity;
	uint32_t head, tail;
public:
	CircularBuffer(uint32_t size) : size(size), p(new uint32_t[size]),
																	head(0), tail(0) {}

	~CircularBuffer() {
		delete [] p;
	}
	
	bool isEmpty() const {
		return head == tail;
	}

	// 1 2 3 4 5 6 7 8 9
	//         h
	//   t
	uint32_t size() const {
    return tail > head ? tail-head : capacity - head+1 + tail;
	}
	
	uint32_t dequeue() {
		uint32_t temp = p[head];
		head = head + 1;
		if (head >= capacity)
			head = 0;
		return temp;
	}

	void enqueue(uint32_t v) {
		if (tail+1 == head)
			grow();
    p[tail] = v;
		tail = tail + 1;
		if (tail >= capacity)
			tail = 0;
		
	}

};
