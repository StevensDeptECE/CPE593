#include <iostream>
using namespace std;

bool isPrime(uint64_t n) {
	for (int i = 3; i <= sqrt(n); i += 2) { //O(sqrt n)  omega(1)
		if (n % i == 0)
			return false;
	}
	return true;
}

int countPrime(uint64_t n) {// O(n * sqrt(n))
	int count = 1;
	for (uint64_t i = 3; i <= n; i += 2)
		if (isPrime(i))
			count++;
	return count;
}

int main() {
	uint64_t n;
	cin >> n;// n= 10000000000001
	cout << isPrime(n) << '\n';
}
