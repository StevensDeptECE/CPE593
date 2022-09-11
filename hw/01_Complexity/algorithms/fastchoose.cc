#include <iostream>
constexpr double nan = 0.0/0.0;
double choose(uint32_t n, uint32_t r) {
	const uint32_t nmax=500, rmax = nmax/2;
	static double memo[nmax][rmax] = {0};
	if (n > nmax || r > nmax)
		return nan;
	if (memo[n][r] != 0)
		return memo[n][r];
	uint32_t bottom = min(r, n-r);
  double num = 1, den = 1;
	for (uint32_t i = bottom; i > 0; i--) {
		num *= n--;
		den *= i;
	}
	return memo[n][r] = num/den;
}

int main() {
	double sum = 0;
	constexpr uint32_t n = 100000000; // 100 million times
	for (uint32_t i = 0; i < n; i++) {
		sum += choose(n,r);
	}
	cout << sum << '\n';
	return 0;
}
