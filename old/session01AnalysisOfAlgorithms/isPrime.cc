#include <iostream>
#include <cmath>

using namespace std;

int isPrime(int n) {
    for (int i = 2; i < n; i++) { //O(n) omega(1)
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int isPrimeBetter(int n) {
    for (int i = 2; i < sqrt(n); i++) { //O(sqrt(n) ) omega(1)
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int bogus(int x) {
    for (int i = sqrt(n); i < n; i++) { // O(n) because n dominates sqrt(n)
    }
}

int main() {
    // test for prime by dividing by every integer smaller than n
    const int n = 1000000000;
    cout << isPrime(n) << '\n';


   // test for prime by dividing by every number up to sqrt
}