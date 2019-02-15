#include <iostream>
using namespace std;
int random(int a, int b) {
	return a + rand() % (b-a+1);
}

// a^n mod m
uint64_t powermod(uint64_t a, uint64_t n, uint64_t m) {
  uint64_t prod = 1; // a^49   49=32 + 16 + 1  = 110001
	while (n > 0) {
    if (n % 2 != 0)
			prod = prod * a % m;
    a = a * a % m;
		n = n /2; // compiler n >>= 1
	}
	return prod;
}
	

bool Fermat(uint64_t p, int k) {
	for (int i = 0; i < k; i++)  {
		uint64_t a = random(2, p-1);
		cout << "testing a=" << a << " p=" << p << '\n';
		if (powermod(a, p-1, p) !=1)
				return false;
	}
	return true; // probably?
}

bool MillerRabin(uint64_t p, int k) {
	for (int i = 0; i < k; i++)  {
		uint64_t a = random(2, p-2);
		cout << "Miller Rabin a=" << a << " p=" << p << '\n';
		uint64_t d = p-1;
		uint64_t s = 0;
		while (d % 2 == 0) {
			s++;
			d  >>= 1;
		}
		// d contains high-order, non-zero bits (stripped low zero bits off)
		// s = # of bits that were stripped off

		uint64_t x = powermod(a, d, p);
		if (x == 1 || x == p-1)
			continue; // this one is good, try until k
		for (int j = 0; j < s-1; j++) {
			x = x * x % p;
		  if (x == 1)
				return false;
			if (x == p-1)
				goto nextTry;

		}
		return false;
	nextTry: ;
	}
	return true; // probably?
}


		
int main() {
	cout << Fermat(17, 3) << '\n';
	cout << Fermat(1000, 5) << '\n';
	cout << Fermat(10001, 5) << '\n';
	cout << Fermat(561, 5) << '\n'; // Carmichael Number 3 * 11 * 17
	cout << MillerRabin(221, 6) << '\n';
}
	
