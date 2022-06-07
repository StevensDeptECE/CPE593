#include <iostream>
#include <cstdlib>
#include <random>
#include <algorithm>
using namespace std;

// generate an array of n random numbers each from 1 to n
void generateQuadratic(int a[], int n) {
	const int c = 100, c2 = 2;
	for (int i = 0, x = -n/2; i < n; i++, x++) {
		a[i] = c - c2*x*x;
	}
}

void print(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}

const double PHI = (sqrt(5)+1)/2;

int goldenMeanSearch(int a[], int n) {
	int L = 0, R = n-1;
	int S = (int) ((R - L) / PHI + 0.5);

	while (L < R) {
		int x1 = R - S, x2 = L + S;
		cout << "x1=" << x1 << "  x2=" << x2 << '\n';
		if (a[x1] > a[x2]) {
			R = x2;
			x2 = x1;
			S = (int) ((R - L) / PHI + 0.5);
			x1 = R - S;
		} else {
			L = x1;		
			x1 = x2;
			S = (int) ((R - L) / PHI + 0.5);
			x2 = L + S;
		}
	}
	return L;
}

int main(int argc, char* argv[]) {
	int n = atoi(argv[1]);
	int a[n];
	generateQuadratic(a, n);
	print(a, n);
	cout << goldenMeanSearch(a, n) << '\n';
}
