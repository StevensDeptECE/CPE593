class BadGrowArray {
private:
	int* data; // int[] data
	int len;
	int capacity;
	void grow() { // double the size

	}
public:
	BadGrowArray() {
		data = nullptr;
		len = 0;
	}
	void insert(int pos, int val) {
		int* old = data;
		data = new int[len+1];
		for (int i = 0; i < pos;i++)
			data[i] = old[i];
		data[pos] = val;
		for (int i = pos+1; i <= len; i++)
			data[i] = old[i-1];
	}
	
	void addEnd(int val) { //O(len)
		int* old = data; // O(1)
		data = new int[len+1]; // O(len)
		for (int i = 0; i < len; i++)    // O(len)
			data[i] = old[i];
		data[len] = val; // O(1)
		len++;
		delete [] old; //O(1)
	}
	void addStart(int val) {
		int* old = data; // O(1)
		data = new int[len+1]; // O(len)
		data[0] = val;
		for (int i = 1; i <= len; i++)
			data[i] = old[i-1];
		len++;
		delete [] old; //O(1)
	}
	void removeStart() {
		int* old = data;
		data = new int[--len];
		for (int i = 1; i <=len; i++)
			data[i-1] = old[i];
		delete [] old;
	}
	void removeEnd() { //O(1)
		len--;
	}
	void remove(int pos);
	uint32_t size() const {
		return len;
	}
	int get(int pos) {
		return data[pos];
	}
	void set(int pos, int val);
};

int main() {
	BadGrowArray a;
	const int n = 1000000;
	for (int i = 0; i < n; i++)
		a.addEnd(i); //O(n)

	// 1  grow = 1
	// 1 2  grow = 2
	// 1 2 3 grow = 4
	// 1 2 3 4
	// 1 2 3 4 5 grow = 8
	// 6, 7, 8
	// add 9 grow to 16 ...


	GrowArray a(2000000);
}
