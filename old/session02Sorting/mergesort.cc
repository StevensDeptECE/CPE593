#include <iostream>
#include <random>
#include <memory.h>
using namespace std;

void mergepartition(int a[], uint32_t L, uint32_t R, int temp[]) {
  if (R-L <= 2) {
    if (R-L <= 1)
      return;
    if (a[L] > a[R])
      swap(a[L], a[R]);
  }
  uint32_t mid = (L + R)/2;
  mergepartition(a, L, mid, temp);
  mergepartition(a, mid+1, R, temp);
}

uint32_t bottomupmergesort(int* list, uint32_t n, int* temp) {
  uint32_t power = 0;
  for (uint32_t p = 1; p <= n/2; p *= 2, power++) {
    int d = 0;
    for (uint32_t part = 0; part < n; part += 2*p) {
      const int* a = list+part;
      const int* b = list + part + p;
#if 0
      // this won't work since the data won't be in the right buffer
      if (a[p-1] < b[0])
        continue; // skip if the list is already sorted
#endif
      uint32_t i = 0, j = 0;
      while(i < p && j < p) {
        if (a[i] < b[j])
          temp[d++] = a[i++];
        else
          temp[d++] = b[j++];
      }
      while (i < p)
        temp[d++] = a[i++];
      while (j < p)
        temp[d++] = b[j++];
      // TODO: add code for handling non-powers of 2
    }
    swap(list, temp); // alternate the temporary space
  }
  return power;
}

void mergesort(int a[], uint32_t n) {
  int* temp = new int[n]; // create temporary storage
  uint32_t power = bottomupmergesort(a, n, temp);
  if (power % 2 != 0)
    memcpy(a, temp, n * sizeof(int));
  delete [] temp;
}

void print(const int a[], uint32_t size) {
  for (uint32_t i = 0; i < size; i++)
    cout << a[i] << ' ';
  cout << '\n';
}

default_random_engine gen;

void shuffle(int a[], uint32_t size) {
  uniform_int_distribution<uint32_t> dist(0,size-1);
  for (uint32_t i = size-1; i > 0; i--) {
    uint32_t r = dist(gen);
    swap(a[i], a[r]);
  }
}
    

template<typename SortFunc>
uint32_t testsort(SortFunc sort, const int* array, uint32_t size) {
  print(array, size);
  int* copy = new int[size];
  memcpy(copy, array, size * sizeof(int));
  clock_t t0 = clock();
  sort(copy, size);
  clock_t t1 = clock();
  print(copy, size);
  return t1-t0;
}

#define testSort(sort, array, size)  cout << "Test " << #sort << "size=" << size << " elapsed=" << testsort(sort, array, size) << "\n==============\n\n";

template<typename SortFunc>
void verifySort(SortFunc sort, uint32_t size) {
  int a[size];
  for (int i = 0; i < size; i++)
    a[i] = i; // fill the array with sequential numbers, all unique
  shuffle(a, size); // put into random order
  sort(a, size); // sort into order again
  int errorCount = 0;
  for (int i = 0; i < size; i++)
    if (a[i] != i) {
      errorCount++;
      //      cerr << i << ": " << a[i] << '\n';
    }
  if (errorCount == 0)
    cout << "sort verify size=" << size << " errors=" << errorCount << '\n';
}

#define size(t) (sizeof(t)/sizeof(int))
int main() {
  int test0[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int test1[] = {8, 7, 6, 5, 4, 3, 2, 1};
  int test2[] = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

#if 0
  int test1[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  int test2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int test3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int test4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int test5[] = {1, 6, 2, 8, 9, 7, 5, 3, 4};
  int test6[] = {6, 9, 7, 2, 10, 5, 8, 4, 3};
#endif
  testsort(mergesort, test0, size(test0));
  testsort(mergesort, test1, size(test1));
  testsort(mergesort, test2, size(test2));
  for (uint32_t n = 1; n < 1024*1024; n *= 2)
    verifySort(mergesort, n);
  
#if 0
  for (uint32_t size = 10; size < 1000000; size *= 10) {
    verifySort(mergesort, size);
    verifySort(mergesort, size+1);
  }

  testsort(mergesort, test1, size(test1));
  testsort(mergesort, test2, size(test1));
  testsort(mergesort, test3, size(test1));
  testsort(mergesort, test4, size(test1));
  testsort(mergesort, test5, size(test1));
  testsort(mergesort, test6, size(test1));
#endif
}
