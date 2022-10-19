#include "util/benchmark.hh"

void intloop(const uint64_t n) {
	for (uint64_t i = 0; i < n; i++)
		;
}

uint64_t sumintloop(const uint64_t n) {
	uint64_t sum = 0;
	for (uint64_t i = 0; i < n; i++)
		sum += i;
	return sum;
}

int main() {
	const uint64_t n = 1000000;
	benchmark::benchmark("int loop", n, intloop);
	benchmark::benchmark("sum loop", n, sumintloop);
	return 0;
}
	
