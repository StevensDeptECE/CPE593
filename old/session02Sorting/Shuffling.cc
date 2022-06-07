#include <iostream>
#include <random>
using namespace std;

default_random_engine gen(0);

void bruteForceShuffle(int a[], int n) {
  uniform_int_distribution<int> distribution(0, n-1);
  int r;
  int b[n];
  for (int i = 0; i < n-1; i++) {
    do {
      r = distribution(gen);
    } while (a[r] >= 0); // 1 + (n-1)/n(1) + 1/n((n-1)/n(2) + 1/n(....)    )
    // 1 + 1 + 1 + 1 +                                        + n + n + n
    b[count++] = r;
    a[r] = -1;
  }
  for (int i = 0; i < n; i++)
   cout << a[i] << ' ';
   cout << '\n';

}

void badShuffle(int a[], int n) {
  uniform_int_distribution<int> distribution(0, n-1);
  int r;
  for (int i = 0; i < n-1; i++) {
    r = distribution(gen);
    swap(x[i], x[r]);
  }

void FischerYates(int a[], int n) {
  int r;
  for (int i = n-1; i > 0; i--) {
    uniform_int_distribution<int> distribution(0, i);
    r = distribution(gen);
    swap(x[i], x[r]);
  }




int main() {
  int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  bruteForceShuffle(a, sizeof(a)/sizeof(int));


}