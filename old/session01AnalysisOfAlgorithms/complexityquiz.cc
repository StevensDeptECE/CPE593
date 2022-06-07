#include <iostream>
using namespace std;
#if 0
bool isPrime(uint64_t n) {
	for (uint64_t i = 2; i < n; i++) { //O(n)
		if (n % i == 0)
			return false; // omega(1)
	}

	return true;
}


//sum(1000000000, 1000000001)
uint64_t sum(uint64_t a, uint64_t b) {   //O(b-a)
	uint64_t s = 0;
	for (uint64_t i = a; i <= b; i++) {
		s += i;
	}
	return s;
}


uint64_t sum(uint64_t a, uint64_t b) {   //O(1)
	return (b*(b+1) - a*(a+1))/2;
}

// 1, 1, 2, 3, 5, 8, ...
//a = 2
//b=3
// c= 3
int fibo(int n) {//O(n)
	int a = 1, b = 1, c;
	for (int i = 0; i < n; i++) { //O(n)
		c = a + b; // O(1)
		a = b;  //O(1)
		b = c;  //O(1)
	}
	return c;
}

#endif

uint64_t fibo(int n) {
	if (n <= 2)
		return 1;
	return fibo(n-1) + fibo(n-2);
}

uint64_t memoized_fibo(int n) {
	static uint64_t sum[200] = {0};
	if (n <= 2)
		return 1;
	if (sum[n] > 0)
		return sum[n];
	return sum[n] = fibo(n-1) + fibo(n-2);
}


//O(1)
double choose(int n, int r) { // choose(52,6), choose(52,5), choose(53,6), choose(53,9)
	static double ans[500][500];

	///store Choose(0,0), choose(2,0), choose(4,0), choose(0,2)
	/*

	  * 0 * 0 * 0 0 0
		0 0 0 0 0 0 0 0
		* 0 * 0 * 0 0 0
		0 0 0 0 0 0 0 0
		* 0 0 0 * 0 0 0
	*/
}


int  main() {
	uint64_t n;
	cin >> n;
	cout << fibo(n);
	return 0;
}
