#include <iostream>
#include <cstdlib>
using namespace std;

int random(int a, int b) {
	return a + rand() % (b-a+1);
}


// a^n mod m
uint64_t powermod(uint64_t a, uint64_t n, uint64_t m) {
	uint64_t prod = 1;  // suppose a^49 = 1 + 16+32    110001
	while (n > 0) {
		if (n % 2 != 0)
 			prod = (prod * a) % m;
    a = (a * a) % m;
		n = n/2;
	}
  return prod;
}


//Carmichael Number 562 = 3 * 11 * 17
bool fermat(uint64_t p, int k) {
	for (int i = 0; i < k; i++) {
		uint64_t a = random(2, p-1);
		cout << "testing a=" << a << " p = " << p << '\n';
		if (powermod(a, p-1, p) != 1)
			return false;
	}
	return true;
}

bool MillerRabin(uint64_t p, int k) {
	for (int i = 0; i < k; i++) {
		uint64_t a = random(2, p-2);
		// d is the nonzero, leading digits of p-1

		int s = 0;
		uint64_t d = p-1; //       100011101
		uint64_t mask = 1;// 000000000000001
		while (d & mask == 0) {
			s++;
			d >>= 1;
		}
		
		uint64_t x = powermod(a, d, p);
		if (x == 1 || x == -1)
			continue;
    for (int i = 0; i < s-1; i++) {
			x = (x * x) % p;
			if (x == n-1)
				goto nextTrial; // this one worked
		}
    return false;
	nextTrial:	
	}
	return true; // probably
}

int main() {
	cout << fermat(561, 5) << '\n';
	cout << fermat(1000, 5) << '\n';
	cout << fermat(10001, 5) << '\n';
	cout << fermat(17, 5) << '\n';


}
