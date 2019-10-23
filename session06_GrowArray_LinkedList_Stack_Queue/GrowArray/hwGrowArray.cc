class Point {
public:
  double x,y;
};

template<typename T>
class GrowArray {
private:
  int capacity; // the amount of memory allocated
  int used;     // the current size of the list
  T* data;
  void grow() {}
public:
  GrowArray() : capacity(1), used(0), data(new int[1]) {}
  GrowArray(int initialSize) {} // set initial capacity
	~GrowArray() {
		delete [] data;
	}
	GrowArray(const GrowArray& orig) = delete;
	GrowArray& operator =(const GrowArray& orig) = delete;
  void addEnd(T v) {}
  void addStart(T v) {}
  void insert(int i, T v) {}
  void removeEnd() {}
  void removeStart() {}
  void remove(int i) {}
  int size() const {  }// return how many elements in the list
}
