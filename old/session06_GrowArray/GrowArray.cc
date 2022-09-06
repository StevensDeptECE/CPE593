class GrowArray {
private:
	int used;
	int capacity;
	int* data;
	void grow() {} // double the size of the list
public:
	GrowArray(int initialCapacity) {}
	GrowArray() {} // create default capacity=1 list
	~GrowArray() {}
	void addEnd(int v) {}  // 1 + (1 + 1) + (2 + 1 + 1) + (4 + 1 + 1 + 1 + 1
	void addStart(int v) {}
	int removeEnd() {}
	int removeStart() {}
	int size() const { return used; }
};

class CircularBuffer {
private:
	int* data;
	int head, tail;
};

int main() {
	GrowArray g(1000);
	for (int i = 0; i < 1001; i++)
		g.addEnd(i); // 1 + 1 + 1 + 1 ...  + 1000
	g.addStart(5); //O(n)
	g.removeEnd(); // O(1)
	g.removeStart(); // O(n)
