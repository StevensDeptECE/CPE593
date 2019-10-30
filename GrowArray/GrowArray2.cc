// in Java this is called ArrayList
// in C++ this is called vector

class GrowArray {
private:
	int* data;
	int used;
	int capacity;
	void grow() {
		// DOUBLE EACH TIME!!!
	}
	void checkGrow() {
		if (used == capacity)
			grow();
	}
public:
  void addEnd(int v) { //O(1)
		checkGrow();

	}
	void addStart(int v); // O(n)

	void removeEnd() {

	}
};
