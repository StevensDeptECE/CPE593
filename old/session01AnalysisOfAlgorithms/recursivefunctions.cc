#include <iostream>

using namespace std;

int fibo(int n) { //O(n)
	int a = 1, b = 1, c;
	for (int i = 0; i < n; i++) { //O(n)
		c = a + b;
		a = b;
		b = c;
	}
	return n;
}

uint64_t fibo2(int n) { //O(2^n)
	if (n <= 2)
		return 1;

	return fibo2(n-1) + fibo2(n-2);
}

uint64_t memoized_fibo2(int n) {
	static uint64_t fibo[200] = {0};
	
	if (n <= 2)
		return 1;
  if (fibo[n] != 0)
		return fibo[n];
	return fibo[n] = memoized_fibo2(n-1) + memoized_fibo2(n-2);
}

main() {
	int n;
	cin >> n;
	cout << memoized_fibo2(n);

}
