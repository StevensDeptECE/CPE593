#include <iostream>
using namespace std;
/**
   0  0  v  v  v  v  v  v
   t     h                       

   v  v  v  0  0  0  0  0
   h        t

   v  v  v  v1  v  v  v  v
            ht
// growing should not do this:
   v  v  v  v  v  v  v  v  0  0  0  0  0  0  0  0
            h

   v1  v  v  v  v  v  v  v  0  0  0  0  0  0  0  0
    h                       t

 */
template<typename T>
class CircularBuffer {
private:
	int size;
	T* data;
	int head, tail;
	void grow() { //O(n)
		T* old = data;
		data = new T[size+size];
		// first copy from head to end of old buffer
		int j = 0;
		for (int i = head; i < size; i++, j++)
			data[j] = old[i];
    for (int i = 0; i < head; i++, j++)
			data[j] = old[i];
		head = 0;
		tail = size;
		size = size+size; // double it
		delete [] old;
	}
public:
	CircularBuffer(int initialSize)
		: size(initialSize), data(new T[initialSize]), head(0), tail(0) {}
	bool isEmpty() const {
		return tail == head;
	}
	void enqueue(const T& v) {
    data[tail] = v;
		tail = tail + 1;
		if (tail >= size)
			tail = 0;
		if (head == tail) { // just became full
			grow();
		}
	}
	int dequeue() {
    int v = data[head];
		head = head + 1;
		if (head > size)
			head = 0;
		return v;
	}
};

int main() {
  CircularBuffer<int> c(10);
	for (int i = 0; i < 20; i++)
		c.enqueue(i);
	while (!c.isEmpty())
		cout << c.dequeue();
}

