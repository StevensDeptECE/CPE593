#include <iostream>
#include <random>
#include <cstring>
using namespace std;

public class HashMapLinearProbing {
private static  class Node {
    int key;
    int val;
  };
  int size;
  int capacity;
  Node[] table;

// these-are-the-bits-of-my-numberxx
//              these-are-the-bits-o
// f-my-numberxx
  private int hash(int key) {
    key = key ^ (key >>> 13) ^ (key << 19);
    key = key ^ (key >>> 8) ^ (key << 24);
    return key % capacity; // return a hashed bin number from 0 to capacity-1
  }
  private int hash2(int key) {
    key = key ^ ((key >>> 13) | (key << 19)); //C++ optimizer will actually turn this into a rotate (right 13 or left 19)
    key = key ^ ((key >>> 8) | (key << 24));
    return key & (capacity-1); // return a hashed bin number from 0 to capacity-1 (capacity MUST BE power of 2!!!)
  }
  private void grow() {
    const Node[] old = table; // remember the old table
    table = new Node[capacity * 2];
    size = 0;
    for (int i = 0; i < capacity; i++)
      if (old[i].key != 0) {
        add(old[i].key, old[i].val);
      }
    capacity *= 2;
  }
public HashMapLinearProbing(int capacity) {
    size = 0;
    this.capacity = capacity;
    table = new Node[capacity];
  }

  public void add(int key, int val) { //O()
    int bin = hash(key);
    while (table[bin].key != 0) { // while something is there (collision)
      if (table[bin].key == key) {
        table[bin].val = val; // replace the existing value in the hashmap
        return; // and get out!
      }
      bin++;
      if (bin >= capacity)
        bin = 0;
    }
    // when we get out, what is the invariant? What are we guaranteed?
    //table[bin].key = 0
    if (size*2 >= capacity)
      grow();
    table[bin].key = key;
    table[bin].val = val;
    size++;
  }
  // return null if not found, or pointer to the corresponding value
  public Integer get(int key) const {
    int bin = hash(key); //O(1)
    while (table[bin].key != 0) {
      if (table[bin].key == key) {
        return table[bin].val; // return a pointer to the corresponding value
      }
      bin++;
      if (bin >= capacity)
        bin = 0;
    }
    return null; // not present!
  }

  public void printHistogram() {
    int hist[] = new int[10];
    // hist[0] = number of bins with 0 collisions
    // hist[1] = number of bins with 1 collision (the original hash value was 1 to left)
    // hist[2] = number of bins with 2 collisions (original hash value was 2 to left)

    // hist[9] = number of bins with 9 OR MORE collisions
    for (int i = 0; i < capacity; i++) {
      int key = table[i].key;
      if (key == 0)
        hist[0]++;
      else {
        int bin = hash(key);
        if (bin - i < 9)
          hist[bin-i]++;
        else
          hist[9]++;
      }
    }
    for (int i = 0; i < 10; i++)
      System.out.println(i  + ": "  + hist[i]);
  }
  public static void main(String[] args) {
    java.util.Random r = 
    HashMapLinearProbing m = new HashMapLinearProbing(1024); // initialize with the number of bins desired
      
      //Unsupported HashMapLinearProbing m2 = m;
    
      final int n = 512;
    /*
      for (int i = 0; i < n; i++)
        m.add(distribution(gen), i);
      m.printHistogram();
      */
      for (int i = 0; i < n; i++)
        m.add(i, i*2);
      
      for (int i = 0; i< 10; i++) {
        Integer p = m.get(i);
        if (p != null) {
          //cout << i << "==>" << *p << '\n';
        }
      }
    
      
    
    }
  }
}

