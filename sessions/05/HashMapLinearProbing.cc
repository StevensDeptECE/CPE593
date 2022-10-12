#include <iostream>
#include <random>
#include <cstring>
using namespace std;

class HashMapLinearProbing {
private:
  struct Node {
    uint32_t key;
    uint32_t val;
  };
  uint32_t size;
  uint32_t capacity;
  Node* table;

// these-are-the-bits-of-my-numberxx
//              these-are-the-bits-o
// f-my-numberxx
  uint32_t hash(uint32_t key) const {
    key = key ^ (key >> 13) ^ (key << 19);
    key = key ^ (key >> 8) ^ (key << 24);
    return key % capacity; // return a hashed bin number from 0 to capacity-1
  }
  uint32_t hash2(uint32_t key) const {
    key = key ^ ((key >> 13) | (key << 19)); //C++ optimizer will actually turn this into a rotate (right 13 or left 19)
    key = key ^ ((key >> 8) | (key << 24));
    return key % capacity; // return a hashed bin number from 0 to capacity-1
  }
  void grow() {
    const Node* old = table; // remember the old table
    table = new Node[capacity * 2];
    memset(table, 0, capacity * 2 * sizeof(Node));
    size = 0;
    for (uint32_t i = 0; i < capacity; i++)
      if (old[i].key != 0) {
        add(old[i].key, old[i].val);
      }
    capacity *= 2;
    delete [] old;
  }
public:
  HashMapLinearProbing(uint32_t capacity) : size(0), capacity(capacity), table(new Node[capacity]){
    for (uint32_t i = 0; i < capacity; i++)
      table[i].key = 0;
  }
  ~HashMapLinearProbing() {
    delete [] table;
  }

  HashMapLinearProbing(const HashMapLinearProbing& orig) = delete;
  HashMapLinearProbing& operator =(const HashMapLinearProbing& orig) = delete;

  void add(uint32_t key, uint32_t val) { //O()
    uint32_t bin = hash(key);
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
  const uint32_t* get(uint32_t key) const {
    uint32_t bin = hash(key); //O(1)
    while (table[bin].key != 0) {
      if (table[bin].key == key) {
        return &table[bin].val; // return a pointer to the corresponding value
      }
      bin++;
      if (bin >= capacity)
        bin = 0;
    }
    return nullptr; // not present!
  }

  // return true if found, if true, set val by reference
  bool get(uint32_t key, uint32_t& val) {
    return false; // TODO: implement me!
  }

  void printHistogram() const {
    uint32_t hist[10] = {0};
    // hist[0] = number of bins with 0 collisions
    // hist[1] = number of bins with 1 collision (the original hash value was 1 to left)
    // hist[2] = number of bins with 2 collisions (original hash value was 2 to left)

    // hist[9] = number of bins with 9 OR MORE collisions
    for (uint32_t i = 0; i < capacity; i++) {
      uint32_t key = table[i].key;
      if (key == 0)
        hist[0]++;
      else {
        uint32_t bin = hash(key);
        if (bin - i < 9)
          hist[bin-i]++;
        else
          hist[9]++;
      }
    }
    for (uint32_t i = 0; i < 10; i++)
      cout << i << ": " << hist[i] << '\n';
  }
};

int main() {
  default_random_engine gen(0); // source of bits
  uniform_int_distribution<uint32_t> distribution(1,1000000);
  HashMapLinearProbing m(1024); // initialize with the number of bins desired
  
  //Unsupported HashMapLinearProbing m2 = m;

  constexpr uint32_t n = 512;
  #if 0
  for (uint32_t i = 0; i < n; i++)
    m.add(distribution(gen), i);
  m.printHistogram();
  #endif
  for (uint32_t i = 0; i < n; i++)
    m.add(i, i*2);
  
  for (uint32_t i = 0; i< 10; i++) {
    const uint32_t* p = m.get(i);
    if (p != nullptr) {
      cout << i << "==>" << *p << '\n';
    }
  }

  

}