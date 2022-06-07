#include <iostream>
using namespace std;
uint64_t* primes;

bool is_prime(uint64_t* primes, uint64_t i) {
	i /= 2; // get the bit position

	return primes[i / 64] & (1 << (i % 64));
}

void clear_prime(uint64_t* primes, uint64_t i) {
}


uint64_t eratos(uint64_t n) {

	// 1 3 5 7 9 11 13 ...   127
	// 0 1 2 3 4 5  6
	const uint64_t WORDS = (n + 127) / 128;
	primes = new uint64_t[WORDS ];
	for (uint64_t i = 0; i < words; i++)
		primes[i] = -1LL;
	uint64_t count = 1; // 2 is prime, special case

	uint64_t lim = sqrt(n);
	for (uint64_t i = 3; i <= lim; i += 2) {
    if (is_prime(primes, i)) {
			count++;
			for (uint64_t j = i*i; j <= n; j += 2*i)
				clear_prime(primes, j);
		}
	}
 
  //  3 5 7 9 11 13 15 17 19 21 23 25 ...  127   129 131 133....
	//	    1 1 1 0 1  1   0  1  1  0  1  1 

				//				3*5*7 = 105 = 2^6 = 64 = lcm(105, 64) = 105*64 

	//	10**9/64 words


	// 3*5*7*11*13 = 15015



	

	delete [] isprime;

}

// 3*3 = 9, 15, 21, 27, .... 123
void pass1(uint64_t primes, uint64_t n) {
  uint64_t m3 = 3*3;
	uint64_t m5 = 5*5;
	uint64_t m7 = 7*7;
	uint64_t w = -1LL;
	for (uint64_t i = 128, j = 0; i <= n; i+= 128, j++) {
		while (m3 < i) {
			clear(w, m3);
			m3 += 6;
		}
		while (m5 < i) {
			clear(w, m5);
			m5 += 10;
		}
		while (m7 < i) {
			clear(w, m7);
			m7 += 14;
		}
		primes[j] = w;
	}

		
	
}

void pass2(uint64_t primes, uint64_t n) {
  uint64_t m11 = 13*13;
	uint64_t m13 = 5*5;
	uint64_t m17 = 7*7;
	uint64_t w = -1LL;
	for (uint64_t i = 128, j = 0; i <= n; i+= 128, j++) {
		while (m3 < i) {
			clear(w, m3);
			m3 += 6;
		}
		while (m5 < i) {
			clear(w, m5);
			m5 += 10;
		}
		while (m7 < i) {
			clear(w, m7);
			m7 += 14;
		}
		primes[j] = w;
	}
}
uint64_t maybefasteratos(uint64_t n) {
	const uint64_t WORDS = (n + 127) / 128;
	primes = new uint64_t[WORDS ];
	uint64_t count = 1; // 2 is prime, special case
  pass1(primes, n);
	uint64_t lim = sqrt(n);
