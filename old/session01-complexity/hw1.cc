#include <iostream>
#include <random>
using namespace std;

// don't implement fact
double fact(int n) { return 0; }

// do memoization using 2d table
double choose(int n, int r) {
	static double memo[101][101] = {0};

	// Don't compute it this way! Be smarter!
	return fact(n) / (fact(r) * fact(n-r));
}

//choose(7,3) = fact(7) / (fact(3)*fact(4)) = 7 * 6 * 5 / ( 3 * 2 * 1)

int main() {
	const int numTrials = 100000000; // 10^8

	double s = 0;
	int n, r;

	default_random_engine generator;
  uniform_int_distribution<int> distribution(1,100);
	for (int i = 0; i < numTrials; i++) {
		n = distribution(generator);
		uniform_int_distribution<int> chooser(0,n);
		r = chooser(generator);
		s += choose(n, r);
	}
	cout << s;
}
