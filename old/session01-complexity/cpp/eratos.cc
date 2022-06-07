#include <time.h>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  clock_t t0 = clock();
  bool* isPrime = new bool[n];
  for (int i = 3; i <= n; i+= 2)
    isPrime[i] = true;
  int count = 1; // special case for 2
  for (int i = 3; i <= n; i += 2) {
    if (isPrime[i]) {
      count++;
      for (int j = i*i; j <= n; j += 2*i)
        isPrime[j] = false;  
    }
  }
  delete [] isPrime;
  clock_t t1 = clock();

  cout << count << " elapsed: " << (t1-t0) << '\n';

}