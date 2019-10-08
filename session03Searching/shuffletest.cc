/*
	Test shuffling algorithms and display histograms to determine whether they are "fair"
	Dov Kruger and CPE593 class 2017/09/12
 */

#include <iostream>
#include <random>

using namespace std;
default_random_engine generator;

void fisherYatesShuffle(int a[], int n) {

	for (int i = n-1; i > 0; i--) {
		uniform_int_distribution<int> dist(0,i);
		swap(x[i], x[dist(generator)]);
	}
}

void badShuffle(int a[], int n) {
	uniform_int_distribution<int> dist(0,n-1);
	for (int i = n-1; i > 0; i--) {
		swap(x[i], x[dist(generator)]);
	}
}

void testShuffle(int n, int trials) {
	int a[n];
	int histogram[n][n]; //count how many times each element [n] has value 0, 1, 2, ... n-1
	//exa: histogram[0][0] is the number of times a[0] has value 0
	for (int t = 0; t < trials; t++) {
		for (int i = 0; i < n; i++)
			a[i] = i;
		badShuffle(a, n);
		// count results into histogram
	}
	// write out histogram to text file
	// display using matlab or other graphical tool
	// see google code jam: https://code.google.com/codejam/contest/2984486/dashboard#s=p2
}

int main() {
	generator.seed(0);               // always start testing with a deterministic random number generator!
	int n = 10;
	int trials = 10;
	testShuffle(n, trials);
	for (int i = 0; i < 20; i++)
		cout << dist(generator);
	cout << '\n';
}
