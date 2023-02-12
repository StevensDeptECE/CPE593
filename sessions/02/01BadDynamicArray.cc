#include <iostream>
using namespace std;

class BadDynamicArray {
private:
  int* data;
  uint32_t size;
public:
  BadDynamicArray() : data(nullptr), size(0) {  }
  ~BadDynamicArray() {
    delete [] data;
  }
  BadDynamicArray(const BadDynamicArray& orig) = delete;
  BadDynamicArray& operator =(const BadDynamicArray& orig) = delete;
  void addEnd(int v) { //O(n)
    const int* old = data;
    data = new int[size+1];
    for (int i = 0; i < size; i++)
      data[i] = old[i];
    delete [] old;
    data[ size ] = v;
    size++;
  }
  void addStart(int v) { //O( n )
    const int* old = data;
    data = new int[size+1];
    data[0] = v;
    for (int i = 1; i <= size; i++)
      data[i] = old[i-1];
    delete [] old;
    size++;
  }
  void insert(int index, int v) { //O(n)
    const int* old = data;
    data = new int[size + 1];
    for (int i = 0; i < index; i++)
      data[i] = old[i]; // copy all the elements BEFORE insert
    data[index] = v;
    for (int i = index+1; i <= size; i++)
      data[i] = old[i-1];
  }
  void removeEnd() { //O(1) but you don't get the memory back
    size--;
  }

// old = [3 1 4]
//data = [1 4]
  void removeStart() { //O(n)
    const int* old = data;
    data = new int[size-1];
    for (int i = 1; i < size; i++)
      data[i-1] = old[i];
    delete [] old;
    size--;
  }

  uint32_t getSize() const { //O(1)
    return size;
  }
  friend ostream& operator <<(ostream& s, const BadDynamicArray& list) {
    for (int i = 0; i < list.size; i++)
      s << list.data[i] << " ";
    return s;
  }
};

void f(BadDynamicArray x) {

}

int main() {
    BadDynamicArray a;
    const int n= 500000;
    for (int i = 0; i < n; i++)
      a.addEnd(i);
    for (int i = 1; i < n; i++)
      a.removeEnd();
    cout << a << '\n';
//    BadDynamicArray b = a;  
//    f(a);

}
