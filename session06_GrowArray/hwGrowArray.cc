class Point {
public:
  double x,y;
};

template<typename T>
class GrowArray {
private:
  T* data;
  int capacity;
  int used;
  void grow() {}
public:
  GrowArray() {}
  GrowArray(int initialSize) {} // set initial capacity
  void addEnd(T v) {}
  void addStart(T v) {}
  void insert(int i, T v) {}
  void removeEnd() {}
  void removeStart() {}
  void remove(int i) {}
  int size() const {  }// return how many elements in the list
}
