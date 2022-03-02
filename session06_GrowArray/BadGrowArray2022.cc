#include <iostream>

template<typename T>
class BadGrowArray {
private:
	T* p;
	int size;
public:
	BadGrowArray() : p(nullptr), size(0) {}
	~BadGrowArray() {
		delete [] p;
	}
	// there is no copy constructor or operator =
  BadGrowArray(const BadGrowArray& orig) = delete;	
  BadGrowArray& operator =(const BadGrowArray& orig) = delete;	
  void addEnd(int v) { // O( n  )
		int* old = p; //O(1)
    p = new int[size+1]; //O(1)
    //memcpy(p, old, size* sizeof(int));
    for (int i = 0; i < size; i++) //O(n)
      p[i] = old[i];
    p[size] = v;
    delete [] old;
    size++;
	}
	void addStart(int v) { // O(n)
		int* old = p;
    p = new int[size+1]; //O(1)
		p[0] = v;
		for (int i = 0; i < size; i++) // O(n)
			p[i+1] = old[i];
    delete [] old;
    size++;
	}

	void insert(int pos, int v) { //O(n)
		int* old = p;
    p = new int[size+1]; //O(1)

    for (int i = 0; i < pos; i++)
			p[i] = old[i];
		p[pos] = v;
    for (int i = pos; i < size; i++)
			p[i+1] = old[i];
    delete [] old;
    size++;		
	}
	
	void removeEnd() { // O(n)
		int* old = p;
		p = new int[size-1];
		for (int i = 0; i < size-1; i++)
			p[i] = old[i];
		delete [] old;
    size--;
	}

	void removeStart() { // O(??)

	}

	int getSize() const { // O(??)

	}

	
};

void f(BadGrowArray<int> x) {

}

int main() {
	for (uint64_t i = 0; i < 1000000000000; i++) {
		BadGrowArray<int> a;
	}

	BadGrowArray<int> c;
	c.addEnd(5);
	f(c); // makes a copy
	BadGrowArray<int> d = c;
	

	BadGrowArray<double> b;


}
