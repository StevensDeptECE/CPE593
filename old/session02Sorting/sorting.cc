#include <iostream>
#include <random>
using namespace std;

mt19937 rnd(0); // always test with random number generator seeded to a specific value
// random numbers will always be the same in every run, which is boring!
// when code works, remove the zero and it will seed with the time

// generate n random integerws from 0 to maxInt
int* generateRandom(int n, int maxInt) {
  int* p = new int[n];
  uniform_distribution<> r(0, maxInt);
  for (int i = 0; i < n; i++)
    p[i]  = r(rnd);
  return p;
}

bool increasing(int x[], int n) {
  for (int i = 0; i < n-1; i++)
    if (x[i] > x[i+1])
      return false;
  return true;
}

void test(int trials, int n) {
  for (int t = 0; t < trials; t++) {
    int* p = generateRandom(n, n);
    sort(p, n);
    increasing(p, n);
    delete[] p;
  }
}

int case1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int case2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int case3[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int case4[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int case5[] = {1, 2, 2, 2, 8};


void bubbleSort(int x[], int n) {
  for (int i = 0; i < n-1; i++)
    for (int j = 0;

int main() {
  test(1000, 10);
  test(1000, 11);
  testCase(case1, sizeof(case1)/sizeof(int));
  testCase(case2, sizeof(case2)/sizeof(int));
  testCase(case3, sizeof(case3)/sizeof(int));
  testCase(case4, sizeof(case4)/sizeof(int));
}		       
