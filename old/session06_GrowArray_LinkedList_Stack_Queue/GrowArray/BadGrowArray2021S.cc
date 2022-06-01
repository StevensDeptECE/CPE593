#include <iostream>
#include <memory.h>
using namespace std;

class BadGrowArray {
private:
	uint64_t len;
	int* data; // address 2**64 = 16 quadrillion bytes
public:
  BadGrowArray() : data(nullptr), len(0) {}

	~BadGrowArray() {
		clear();
	}
	BadGrowArray(const BadGrowArray& orig) : data(new int[orig.len]), len(orig.len)	{// copy constructor
		memcpy(data, orig.data, sizeof(int)*len);
	}

	// old style operator =
#if 0
	BadGrowArray& operator =(const BadGrowArray& orig) { // copy constructor
		if (this != &orig) {
			delete [] data;
			data = new int[orig.len];
			len = orig.len;
			memcpy(data, orig.data, sizeof(int)*len);
		}
    return *this;
	}
#endif
	//copy and swap
	BadGrowArray& operator =(BadGrowArray copy) { // copy constructor  O(len)
		swap(data, copy.data);//O(1)
		len = copy.len;
    return *this;
	}

	void addEnd(int v) { //O(len)
		const int* old = data; // remember the old memory O(1)
		data = new int[len+1];// allocate new memory to hold existing list + new element O(1)
		for (int i = 0; i < len; i++) // copy old to new O(len)
	    data[i] = old[i];
		//		memcpy(data, old, len * sizeof(int)); // faster than loop, but same complexity
		delete [] old; // delete old memory (in Java, you don't do this, the garbage collector does it)
		data [len++ ] = v; // add new element to the end and increment len after
	}
	void addStart(int v) {
		const int* old = data;
		data = new int[len+1];
		data [0] = v; // add new element to the start
		for (int i = 1; i <= len; i++)
	    data[i] = old[i-1];
		delete [] old;
		len++;
	}
	//	void add(int v, int pos) {
	//	}
	
	void removeEnd() { //O(1)
		len--;
	}
	void removeStart() { //O(len)
		const int* old = data;
		data = new int[--len];
		for (int i = 0; i < len; i++)
	    data[i] = old[i+1];
		delete [] old;
	}
	friend ostream& operator <<(ostream& s, const BadGrowArray& a) {
    for (int i = 0; i < a.len; i++)
			s << a.data[i] << ' ';
		return s;
	}

	uint64_t size() const {
		return len;
	}
	
	void clear() {
		delete [] data;
		data = nullptr;
		len = 0;
	}
  int get(uint64_t pos) const {
		return data[pos];
	}
	class Iterator {
	private:
		int* current;
		uint64_t count;
	public:
		Iterator(BadGrowArray& list) {
			current = list.data;
			count = list.len;
		}
		bool operator !() const {
			return count > 0;
		}
		void operator ++() {
			current++;
			count--;
		}

		int operator *()const {
			return *current;
		}
	};
};

int main(int argc, char* argv[]) {
	BadGrowArray list; // empty list
#if 0
	const uint64_t n = atoi(argv[1]);
	
	for (uint64_t i = 0; i < n; i++)
		list.addEnd(i);

	int sum = 0;
	for (uint64_t i = 0; i < n; i++)
		sum += list.get(i);
	cout << sum << '\n';

#endif
	
	cout << list.size() << '\n'; // should print 0
	list.addEnd(5); // O(1)
	for (int i = 0; i < 10; i++) // 2 + 3 + 4 + ... + 11  O(n^2)
		list.addEnd(i);
	list.addStart(9);
	//	list.add(-3, 5); // add -3 to position 5
	cout << list << '\n';
	list.removeEnd();
	list.removeStart();
	cout << list << '\n';
	for (BadGrowArray::Iterator i = list; !i; ++i)
		cout << *i;
	cout << '\n';
	
#if 0
	BadGrowArray list2(list); // make a copy
	BadGrowArray list3 = list; // make a copy
	list3.clear();
	list3.addEnd(4);
	list3 = list; // delete existing list and copy in new list

	list3 = list3;
	// deep copy vs. shallow copy
	// iterate
#endif
}
