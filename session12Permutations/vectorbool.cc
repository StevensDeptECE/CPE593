#include <vector>
#include <bitset>
#include <iostream>
#include <time.h>
using namespace std;

void f(vector<bool>& bits, int n) {
	for (int i = 0; i < n; i++)
		bits[3] = true;
}

void g(uint64_t bits, int n) {
	for (int i = 0; i < n; i++)
		bits |= 1 << 3;
}

#if 0
void* ::operator new(size_t sz) {
	cout << sz << '\n';
	return malloc(sz);
}
#endif

int main() {
	uint64_t bits  = 0;

	bits |= 1 << 5;

	vector<bool> bits2;
	for (int i = 0; i < 64; i++)
		bits2.push_back(false);

	bits2[5] = true;

	cout << sizeof(bits2) << '\n';
	const int n = 10000000;
	
	clock_t t0 = clock();
	f(bits2, n);
	clock_t t1 = clock();
	cout << "vector: " << (t1-t0) << '\n';

	t0 = clock();
	g(bits, n);
	t1 = clock();
	cout << "uint bitvec: " << (t1-t0) << '\n';
}
