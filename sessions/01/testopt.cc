#include <iostream>
using namespace std;

int main() {
	constexpr uint64_t n = 8000000000ULL;
	uint64_t sum = 0;
	for (uint64_t i = 0; i < n; i++)
		sum += i;

	for (int i = 0; i < n; i *= 4)
		;

	for (int i = n*n; i > 5; i /= 4) { // O(log(n))

	}

	for (int i = 5; i < n; i+= 3) {
		for (int j = 3; j < 2 * n; j++) { //O(n^2)

		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			// 0 + 1 + 2 + ... + n-1 = n(n-1)/2 = O(n^2)
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < i; j *= 2) { 
			// 0 + 0 + 1 + ...  log n + log n +   log n
			// n * log (n)
		}
	}


	//	cout << sum << '\n';
}
