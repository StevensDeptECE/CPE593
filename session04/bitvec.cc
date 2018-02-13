#include <iostream>
using namespace std;

class BitVec {
private:
  uint32_t words;
  uint32_t size;
  uint64_t* bits;
public:
  BitVec(uint32_t n, bool value) : words((n+63)/64), size(n), bits(new uint64_t[words]) {
    uint64_t v = value ? 0 : uint64_t(-1LL);
    for (uint32_t i = 0; i < words; i++)
      bits[i] = v;
  }
  //  0000000101010101001x1010101001
  //  000000000000000000000000000001 = 1

  // masking
  //  0000000101010101001x1010101001
  //  000000000000000000000000111111
  // AND0000000000000000000000101001
  //decimal example     120 / 10  shift right
  void set(uint32_t i) {
    //    bits[i / 64] |= 1 << (i % 64);
    bits[i >> 5] |= 1 << (i & 0x3F); //
  }

  void clear(uint32_t i) {
    bits[i >> 5] &= ~(1 << (i & 0x3F)); //
  }

  bool test(uint32_t i) {
    return (bits[i >> 5] & 1 << (i & 0x3F)) != 0;
  }

  
};
