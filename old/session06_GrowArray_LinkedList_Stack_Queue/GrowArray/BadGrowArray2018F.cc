class BadGrowArray {
private:
	int size;
	int* p;
public:
  BadGrowArray() : size(0), p(nullptr) {} 

	void insertEnd(int v) {  //O(n)
		int* old = p;  //O(1)
    p = new int[size + 1];  //O(1)
    for (int i = 0; i < size; i++) //O(size) = O(n)
			p[i] = old[i];
		p[size++] = v;  //O(1)
		delete [] old; //O(1)
	}
	void insertStart(int v) {
		int* old = p;
		p = new int[size+1];
		p[0] = v;
    for (int i = 1; i <= size; i++)
			p[i] = old[i-1];
		size++;
		delete [] old;		
	}
	void insert(int pos, int v) {
		int* old = p;
		p = new int[size+1];
		for (int i = 0; i < pos; i++) //O(n)
			p[i] = old[i];
		p[pos] = v;
		for (int i = pos + 1; i <= size; i++) //O(n)
			p[i] = old[i-1];
		size++;
		delete [] old;		
	}
	void removeStart() {
		for (int i = 0; i < size-1; i++)
			p[i] = p[i+1];
		size--;

	}

	void removeEnd() {
    size--;
	}
	friend ostream& operator <<(ostream& s, const BadGrowArray& b) {
		for (int i = 0; i < b.size; i++)
			s << b.p[i] << ' ';
		return s;
	}
};


int main() {
	BadGrowArray b;
	for (int i = 0; i < 10; i++)
		b.insertEnd(i); // 1 + 2 + 3 + .. + n = O(n^2)
	for (int i = 0; i < 10; i++)
		b.insertStart(i); // 1 + 2 + 3 + .. + n = O(n^2)
	for (int i = 0; i < 10; i++)
		b.insert(5, 99); // 1 + 2 + 3 + .. + n = O(n^2)
	cout << b << '\n';
	for (int i = 0; i < 20; i++)
		b.removeStart();
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
