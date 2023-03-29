#include <iostream>
using namespace std;
//   2   4   7   19  22  35   49  56  98
//   L               g                 R
//   L       g        R
//           L   g    R
//           L   R
//           g
int binary_search(const uint32_t a[], uint32_t n, uint32_t target) {
  int L = 0, R = n-1;
  while(L < R) {
    int guess = (L+R)/2;
     if (a[guess] > target)
    R = guess-1;
  else if (a[guess] < target) {
    L = guess+1;
   } else
     return guess;
  }
  return -1;
}
int binary_search2(const uint32_t a[], uint32_t L, uint32_t R, uint32_t target) {
    if (L >= R)
      return -1;
    int mid = (L+R)/2;
    if (a[mid] > target)
      return binary_search2(a, L, mid-1, target);
    else if (a[mid] < target)
      return binary_search2(a, mid+1, R, target);
    return mid;
}

int main() {
    uint32_t a[] = {2, 6, 8, 9, 12, 15, 30, 31, 32, 39, 59, 60, 61, 98};
    const int n = sizeof(a)/sizeof(uint32_t);
    cout << binary_search(a, n, 16) << '\n';
    cout << binary_search(a, n, 2) << '\n';
    cout << binary_search2(a, 0, n-1, 2) << '\n';

}
