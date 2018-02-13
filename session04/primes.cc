#include <iostream>
using namespace std;

// true means n is prime
//O(n)  omega(1)
bool bruteForceIsPrime(uint64_t n) {   // n =2
  for (uint64_t i = 2; i < n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

/*
  28

2*14
4*7


 */

//O(sqrt(n))
bool bruteForceIsPrime2(uint64_t n) { 
  for (uint64_t i = 2; i <= sqrt(n); i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

//O(n*sqrt(n))
uint64_t countPrimes(uint64_t n) {
  uint64_t count = 0;
  for (uint64_t i = 2; i <= n; i++)
    if (bruteForceIsPrime(i))
      count++;
  return count;
}

int main() {
  cout << bruteForceIsPrime(100000000000000001) << '\n';
  
  cout << countPrimes(n) << '\n';

}
