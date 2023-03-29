#include <iostream>
using namespace std;

//    5  4   3  2  1
//    4  3   2  1  5
//    3  2   1  4  5

// n-1 + n-1 + n-1 + ... + n-1 = (n-1)*(n-1) = O(n^2)

// sum(1..n) = n(n+1)/2
// n-1 + (n-2) + (n-3) + ... + 1 = (n-1)(n-2)/2 = O(n^2)

void bubblesort(uint64_t a[], uint32_t n) { // O(n^2)

  for (uint32_t j = n-1; j > 0; j--) { // O(n)
    for (uint32_t i = 0; i < j; i++) { //O(n-1) = O(n)
      if (a[i] > a[i+1] ) {
        uint64_t temp = a[i];
        a[i] = a[i+1];
        a[i+1] = temp;
      }
    }
  }
}

#if 0
      a[i] ^= a[i+1];
      a[i+1] ^= a[i];
      a[i] ^= a[i+1];
#endif

void improved_bubblesort(uint64_t a[], uint32_t n) { // O(n^2)  omega(n)

  for (uint32_t j = n-1; j > 0; j--) { // O(n)
    int swaps = 0;
    for (uint32_t i = 0; i < j; i++) { //O(n-1) = O(n)
      if (a[i] > a[i+1] ) {
        uint64_t temp = a[i];
        a[i] = a[i+1];
        a[i+1] = temp;
        swaps++;
      }
    }
    if (swaps == 0)
      return;    
  }
}
