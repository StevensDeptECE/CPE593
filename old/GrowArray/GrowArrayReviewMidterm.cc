class GrowArray {
private:
	int* data;
	int len;
	int capacity;
	void grow() {
		capacity = capacity * 2 + 1;
		int* old = data;
		data = new int[capacity];
		for (int i = 0; i < len; i++)
			data[i] = old[i];

	}
public:
	GrowArray(int initialCapacity) : capacity(initialCapacity), len(0), data(new int[capacity]) {

	}
	GrowArray() : len(0), capacity(0), data(nullptr) {}

	void addStart(int v) { //O(len)
		if (len >= capacity)   // Java: len >= data.length
			grow();
		for (int i = len-1; i >= 0; i--)  // 9 9 8 7 4      
			data[i+1] = data[i];
		data[0] = v;
	}
  void removeStart() { //O(len)
		for (int i = 0; i < len-1; i++)
			data[i] = data[i+1];
    len--;
	}
	int removeEnd() { // O(1)
		return data[--len];
	}
  void addEnd(int v) { // O(1, 1, 1, 1, n, 1, 1, 1, 1, 1, 1, 1, 1, n, 

	  if (len >= capacity)
			grow();
		data[len++] = v;
	}
};

	int main() {
		GrowArray a;
		for (int i = 0; i < n; i++)
			a.addEnd(n);
		for (int i = 0; i < n; i++)
			a.addStart(n);

	}
