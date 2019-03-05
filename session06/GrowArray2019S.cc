class GrowArray {
private:
	int* data; // int[] data
	uint32_t len;
	//TODO for homework	uint32_t capacity;
	void grow() { // doubles the size each time  it is called

	}
public:
  GrowArray() : data(nullptr), len(0) {	} //O(1)
	void addEnd(int v) { //O(n)
		int* old = data; //O(1)
		data = new int[len+1]; //O(1)
		for (int i = 0; i < len; i++) // O(len)
			data[i] = old[i];
		delete [] old; // O(1)
		data[len] = v;
		len++;
	}
  void addStart(int v) { //O(len) O(n)
		int* old = data;
		data = new int[len+1];
		data[0] = v;
		for (int i = 1; i <= len; i++)
			data[i] = old[i-1];
		len++;
		delete [] old;
	}

	void removeEnd() {
		int* old = data;
		data = new int[--len];
		for (int i = 0; i < len; i++)
			data[i] = old[i];
		delete [] old;
	}
	void removeEnd() {
		len--;
	}
	void removeStart() {
		int* old = data;
		data = new int[--len];
		for (int i = 0; i < len; i++)
			data[i] = old[i+1];
		delete [] old;
	}

	uint32_t size() const {
		return len;
	}

};

int main() {
	GrowArray a; // empty O(1)
	const int n = 1000000;
	for (int i = 1; i < n; i++) //O(n)
		a.addEnd(i); // O(n)
