#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, b % a);
}

int main() {
	cout << gcd(3025, 1025) << '\n';
	cout << gcd(12, 18) << '\n';
}
