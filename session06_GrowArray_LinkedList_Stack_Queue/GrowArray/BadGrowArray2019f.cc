#include <iostream>
using namespace std;

class BadGrowArray {
private:
	uint32_t len;
  int* p;
public:
	BadGrowArray() : len(0), p(nullptr) {}
	~BadGrowArray() {
		delete [] p; // O(1)
	}
	BadGrowArray(const BadGrowArray& orig) = delete;
	BadGrowArray& operator =(const BadGrowArray& orig) = delete;
	
#if 0
	BadGrowArray(const BadGrowArray& orig) : len(orig.len), p(new int[len]) {
    for (int i = 0; i < len; i++)		
      p[i] = orig.p[i];
	}

	void operator =(const BadGrowArray& orig) {
		if (this == &orig) {
			return;
		}
		delete [] p;
	  len = orig.len;
		p = new int[len];
    for (int i = 0; i < len; i++)		
      p[i] = orig.p[i];
	}
	BadGrowArray& operator =(const BadGrowArray& orig) {
		BadGrowArray copy(orig);
		len = copy.len;
		swap(p, copy.p);
		return *this;
	}
#endif
	
	uint32_t size() const {
		return len;
	}
	int get(uint32_t i) {
		return p[i];
	}
	void addEnd(int v) { //O(n)
		const int* old = p; //O(1)
		p = new int[len+1]; //O(1)
		for (int i = 0; i < len; i++) //O(len)
			p[i] = old[i];
		p[len++] = v; //O(1)
		delete [] old; //O(1)
	}
	void addStart(int v) { //O(n)
		int* old = p;
		p = new int[len+1];
		for (int i = 0; i < len; i++) //O(n)
			p[i+1] = old[i];
		p[0] = v;
		len++;
		delete [] old;
	}
	void removeEnd() { //O(n)
		int* old = p;
		len--;
		p = new int[len];
		for (int i = 0; i < len; i++)
			p[i] = old[i];
		delete [] old;
	}
	void removeStart() { //O(n)
		int* old = p;
		len--;
		p = new int[len];
		for (int i = 0; i < len; i++)
			p[i] = old[i+1];
		delete [] old;
	}
	friend ostream& operator <<(ostream& s, const BadGrowArray& list) {
		for (int i = 0; i < list.size(); i++)
			s << list.p[i] << ' ';
		return s;
	}
};

#if 0
// calls copy constructor
void f(BadGrowArray x) {

}
#endif

int main() {
	BadGrowArray a; // O(1)
	a.addEnd(3); //O(1)
	a.addEnd(1); //O(2)
	a.addEnd(4); //O(3)
	a.addStart(1);
	const int n = 10;
	for (int i = 0; i < n; i++)
		a.addEnd(i); // 1 + 2 + 3 + ... + (n-2) + (n-1) = 
	for (int i = 0; i < a.size(); i++)
		cout << a.get(i) << " ";
	cout << '\n';

	// demonstration of calls to the copy constructor
	//	BadGrowArray b = a;
	//  f(a);
	BadGrowArray b = a; // copy constructor
	BadGrowArray c(a); // copy constructor
	//	f(a);
	BadGrowArray d;
	d.addEnd(5);
	c = d; // operator =

	// you CANNOT IGNORE THIS CASE.... with pointers, it can always happen
	BadGrowArray*p;
	BadGrowArray*q;
	*p = *q;
	
}

	
