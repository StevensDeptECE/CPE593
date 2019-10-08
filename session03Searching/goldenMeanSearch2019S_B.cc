#include <iostream>
#include <random>
#include <cmath>
using namespace std;

const double phi = (1+sqrt(5))/2; // ~1.618

int goldenMeanSearch(int data[], int n) {
	int L = 0, R = n-1;
	int S = (R-L) / phi;
	int x = R - S, y = L + S;
	do {
		if (data[x] > data[y]) {
			R = y;
			y = x;
			S = (R-L) / phi;
			x = R - S;
		} else {
			L = x;
			x = y;
			S = (R-L) / phi;
			y = L + S;
		}
	} while (L < R);
	return data[L];
}

int main() {
	const int n = 21;
	int data[n] = {1, 5, 16, 17, 18, 92, 15, 15, 12, 3, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 0};
	cout << goldenMeanSearch(data, n) << '\n';
}
