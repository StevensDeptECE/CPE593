class BadGrowArray {
private:
  int size;
  int* data;
  
public:
  BadGrowArray() : size(0), data(nullptr) {}
  void addEnd(int v) { //O(n)
    const int* old = data;
    data = new int[size+1];
    for (int i = 0; i < size; i++) // O(size)
      data[i] = old[i];
    data[size] = v;
    size++;
    delete [] old; // you must show us management of memory
  }
  void addStart(int v) { //O(n)
    const int* old = data;
    data = new int[size+1];
    data[0] = v;
    for (int i = 0; i < size; i++)
      data[i+1] = old[i];
    size++;
    delete [] old; // you must show us management of memory
  }
  void insert(int i, int v) { //O(
    const int* old = data;
    data = new int[size+1];
    for (int j = 0; j < i; i++)
      data[j] = old[j];
    data[i] = v;
    size++;
    for (int j = i+1; j < size; j++)
      data[j] = old[j-1];
    delete [] old;
  }
  void removeEnd() { //O(1)
    size--;
  }
  void removeStart() { //O(n)
    size--;
    for (int i = 0; i < size; i++)
      data[i] = data[i+1];
  }
  
  
};

int main(){
  BadGrowArray b;
  b.addEnd(5);
  const int n = 100;
  for (int i = 0; i < n; i++)
    b.addEnd(i);
}
