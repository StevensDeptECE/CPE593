#include <iostream>
#include <cstdint>

// choose (n,r) = n! / (r! (n-r)!) = choose(52, 6) = 52!/(6!46!)

int main() {
    const uint64_t num_trials = 10'000;
//    const uint64_t num_trials = 1000'000;
    const uint32_t nmax = 100, rmax = 50;
    double sum = 0;
    
    for (int i = 0; i < num_trials; i++) {
        for (int n = 1; n <= nmax; n++) {
            for (int r = 1; r <= rmax; r++))
               sum += choose(n , r)

    }
}