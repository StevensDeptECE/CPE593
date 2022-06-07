#include <iostream>
using namespace std;

bool isPrime(uint64_t n) { // O(n)
	for (uint64_t i = 2; i < n; i++) {
		if (n % i == 0) 
			return false; //omega(1)
	}
	return true;
}

// 28 = 1   2   4    7    14   28

//isPrime(100000000000000001)
bool isPrime2(uint64_t n) { // O(sqrt(n))
	for (uint64_t i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) 
			return false; //omega(1)
	}
	return true;
}


int main() {
	const int n = 1000000000;
	const int SIZE = (n+63) / 64;
  uint64_t* p = new uint64_t[SIZE];
	// 3 5 7 9 11
	for (int i = 0; i < SIZE; i++) {
		p[i] = 0xFFFFFFFFFFFFFFFFLL;
		
}
