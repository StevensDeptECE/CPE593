#include <iostream>

bool fermat(uint64_t p, int k) {
  for (int i = 0; i < k; i++) {
    int a = random(2, p-1);

    if (powermod(a, p-1, p) != 1)
      return false;
    // could be false positive
    // could be Carmichael  561 = 3 * 11 * 17

  }
  return true; // we think...
}


bool millerRabin(uint64_t n, int k) {
 witnessLoop:
  for (int i = 0; i < k; i++) {
    int a = random(2, p-2);

    // p must be odd
    // therefore p-1 is DEFINITELY EVEN
    // p = 221  128+64+16+4
    //     221= 11010101
    // p-1    = 11010100
    // s = the number of traling 0 (s=2)
    // d = the leading bits 110101 = 53
    //split the number   d, s

    uint64_t x = powermod(a, d, n);
    if (x == 1 || x == n-1)
      continue;
    for (s--; s > 0; s--) {
      x = (x*x) % n;
      if ( x == n-1)
        continue witnessLoop;
      else
        return false;
    }
  }
  return true;
}
