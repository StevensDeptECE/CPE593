#include <iostream>
using namespace std;

template<typename T>
class GrowArray {
private:
	int capacity;
	int size;
	T* data;
public:
	GrowArray(int capacity) : capacity(capacity), size(0), data(new T[capacity]) {}
	// calls T::T() capacity times

	~GrowArray() {
		delete [] data; // T::~T() capacity times
	}

	GrowArray(const GrowArray& orig) = delete;
	GrowArray& operator=(const GrowArray& orig) = delete;

  void addLast(const T& v) {
		data[size++] = v;
	}
	class Iterator {
	private:
		GrowArray<T>& list;
		int pos;
	public:
		Iterator(GrowArray<T>& list) : list(list), pos(0) {}
		bool operator !() const { return pos < list.size; }
		void operator ++() { pos++; }
		T& operator *() const { return list.data[pos]; }
	};

	class const_Iterator {
	private:
		GrowArray<T>& list;
		int pos;
	public:
		const_Iterator(const GrowArray<T>& list) : list(list), pos(0) {}
		bool operator !() const { return pos < list.size; }
		void operator ++() { pos++; }
		const T& operator *() const { return list.data[pos]; }
	};
};

int main() {
	GrowArray<int> a(10);
	a.addLast(5);
	a.addLast(9);
	for (GrowArray<int>::Iterator i(a); !i; ++i) {
		*i *= 2;
	}
	for (GrowArray<int>::Iterator i(a); !i; ++i) {
		cout << *i << '\t';
	}
	cout << "\n";
}
