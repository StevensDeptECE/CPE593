#include <iostream>
#include <cstdint>
#include <time.h>
using namespace std;

class BadDynamicArray {
private:
  int* data; // pointer does not know how long the block is
  uint32_t capacity;
public:
  BadDynamicArray() : data(nullptr), capacity(0) {}
  ~BadDynamicArray() { delete [] data; }

  // We are not implementing copy constructor or operator == 
  BadDynamicArray(const BadDynamicArray& orig) = delete;
  BadDynamicArray& operator =(const BadDynamicArray& orig) = delete;
  uint32_t len() const { return capacity; }
  void addEnd(int v) {
    int* temp = new int[capacity+1]; //O(1)
    for (uint32_t i = 0; i < capacity; i++) //O(capacity)
      temp[i] = data[i]; 
    temp[capacity] = v;//O(1)
    delete [] data; //O(1)
    data = temp; //O(1)
    capacity++; //O(1)
  }
  void addFirst(int v) {
    int* temp = new int[capacity+1];
    temp[0] = v; // copy in new element O(1)
    for (uint32_t i = 1; i <= capacity; i++) {
        temp[i] = data[i-1];
    }
    delete [] data; //O(1)
    data = temp; //O(1)
    capacity++;
  }

  // insert before position pos
  void insert(uint32_t pos, int v) {}
  void removeEnd() {//O(capacity)
    int* temp = new int[capacity-1];
    for (uint32_t i = 0; i < capacity-1; i++) {
        temp[i] = data[i];
    }
    delete [] data; //O(1)
    data = temp; //O(1)
    capacity--;
  }
  void removeFirst() {//O(capacity)
    int* temp = new int[capacity-1];
    for (uint32_t i = 1; i < capacity; i++) {
        temp[i-1] = data[i];
    }
    delete [] data; //O(1)
    data = temp; //O(1)
    capacity--;
  }
  void remove(uint32_t pos) {}            //TODO: implement!
  void replace(int search, int repl) {} //TODO: implement!
  int get(uint32_t pos) const {
    return data[pos];
  }
  void set(uint32_t pos, int val) {
    data[pos] = val;
  }
  int& operator [](uint32_t pos) {
    return data[pos];
  }
  const int& operator [](uint32_t pos) const {
    return data[pos];
  }
  friend ostream& operator <<(ostream& s, const BadDynamicArray& a) {
    for (int i = 0; i < a.len(); i++)
      s << a[i] << ' ';
    return s;
  }
};

int main() {
#if 0
  BadDynamicArray a1; // empty, preallocated space? 0
  cout << a1.len() << '\n';
  a1.addEnd(3);
  constexpr uint32_t n = 10;
  for (int i = 1; i <= n; i++)
    a1.addEnd(i); // 1 + 2 + 3 + ... + n = O(n^2)
  a1.addFirst(9);
  a1.insert(5, -3);
  cout << a1 << '\n';
  a1.removeEnd();
  a1.removeFirst();
  a1.remove(3);
  cout << a1 << "\n\n";

  int v = a1.get(3);
  int v2 = a1[3];
  a1.set(4, -5);
  a1[4] = -5;
   cout << a1[6] << '\n'; 
   cout << a1[999999] << "\n\n"; 
  a1.replace(-3, +6);
  int x = 3; // initialization
  x = 4; // operator =
//  BadDynamicArray a2 = a1; // make a copy of a1 (copy constructor)
//  BadDynamicArray a3(a1); // copy constructor, alternate syntax
//  a3 = a1; // operator =
#endif
  for (int n = 10; n <= 1000000; n *= 10) {
    cout << "n=" << n << '\n';
    clock_t t0 = clock();
      BadDynamicArray a;
      for (int i = 0; i < n; i++)
        a.addEnd(i);

    clock_t t1 = clock();
    cout << (t1-t0) << '\n';
  }
}
