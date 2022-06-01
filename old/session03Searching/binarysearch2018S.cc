#include <iostream>
#include <cstdlib>
#include <random>
#include <algorithm>
using namespace std;

// generate an array of n random numbers each from 1 to n
void generateRandom(int a[], int n) {
	default_random_engine rng(0);
	uniform_int_distribution<int> u(1, n);
  for (int i = 0; i < n; i++)
		a[i] = u(rng);
}

void print(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}

int bisection(int a[], int n, int target) {
	int L = 0, R = n-1;
  while (L < R) {
		int g = (L + R) / 2;
		if (a[g] > target) {
			R = g-1;
		} else if (a[g] < target) {
			L = g+1;
		} else {
			return g;
		}
	}
	return -1;
}


int main(int argc, char* argv[]) {
	int n = atoi(argv[1]);
	int a[n];
	generateRandom(a, n);
	sort(a, a+n);
	print(a, n);
	int target;
	cin >> target;
	cout << bisection(a, n, target) << '\n';
}
