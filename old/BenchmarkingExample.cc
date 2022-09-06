#include <sys/time.h>

int main() {
	for (int n = 1000000; n <= 100000000; n *= 10) {
		int* a = new int[n];
		int* b = new int[n];
		pickRandom(a, n);
		memcpy(b, a, n * sizeof(int));
		clock_t t0 = clock();
		quicksort(b, n);
		clock_t t1 = clock();
		cout << "quicksort: n= " << n << ": " << (t1-t0)*1e-6 << '\n';
    t0 = clock();
		memcpy(b, a, n * sizeof(int));
		heapsort(b, )
		t1 = clock();
    delete [] a;
    delete [] b;
  }
	
/*
	                 n=10^6   n=10^7  
	Quicksort        time
	Heapsort         time
	Mergesort        time
*/
