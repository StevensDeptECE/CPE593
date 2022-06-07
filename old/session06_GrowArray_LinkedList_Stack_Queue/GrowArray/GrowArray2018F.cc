class GrowArray {
private:
	int capacity; // the size of the block of memory
	int size;     // how many are used
	int* p;       // pointer to the block
	void checkGrow() { // 

	}
public:
  GrowArray() { }
  GrowArray(int initialSize) {}
	
	void insertEnd(int v) { //O(1)
		checkGrow();
		p[size++] = v;
	}
	void insertStart(int v) {
	}
	void insert(int pos, int v) {
	}
	void removeStart() {
	}

	void removeEnd() {
	}
	friend ostream& operator <<(ostream& s, const BadGrowArray& b) {
		for (int i = 0; i < b.size; i++)
			s << b.p[i] << ' ';
		return s;
	}
};


int main() {
	GrowArray b;
	for (int i = 0; i < 10; i++)
		b.insertEnd(i);
	for (int i = 0; i < 10; i++)
		b.insertStart(i);
	cout << b << '\n';
	for (int i = 0; i < 10; i++)
		b.removeStart();
	b.removeEnd();
	cout << b << '\n';
}

/*
   x = [];
   for i=1:1000000
     x = [x, i];
   end
   x = zeros(1, 1000000);
   for i=1:1000000
     x(i) = i;

 */
