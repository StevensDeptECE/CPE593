#include <iostream>
using namespace std;

class BitVec {
private:
  uint32_t words;
  uint32_t size;
  uint64_t* bits;
public:
  BitVec(uint32_t n, bool value) : words((n+63)/64), size(n), bits(new uint64_t[words]) {
    uint64_t v = value ? uint64_t(-1LL) : 0;
    for (uint32_t i = 0; i < words; i++)
      bits[i] = v;
  }
  //  0000000101010101001x1010101001
  //  000000000000000000000000000001 = 1

  // masking
  //  0000000101010101001x1010101001

  //  000000000000000000000000111111 0x3F
  // AND0000000000000000000000101001
  //decimal example     120 / 10  shift right 12
  void set(uint32_t i) {
    //  bits[i / 64] |= 1 << (i % 64);
    bits[i >> 6] |= 1 << (i & 0x3F); //
  }

  //
  //   0000000101010101001x1010101001
  //   000000000000000000010000000000
  //AND111111111111111111101111111111
  //   000000010101010100101010101001
  void clear(uint32_t i) {
    bits[i >> 6] &= ~(1 << (i & 0x3F)); //
  }

  bool test(uint32_t i) {
    return (bits[i >> 6] & 1 << (i & 0x3F)) != 0;
  }

  
};

int main() {
  const int n = 1024*1024;
  BitVec b(n, true);
  for (int i = 4; i < n; i+= 2)
    b.clear(i);
}
