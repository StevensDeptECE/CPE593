#include <random>

void fischeryates(int x[], int n) {
	for (int i = n-1; i > 0; i--) {
    int pick = random(0,n-1);
		swap(x[pick], x[i]);
	}
}

void tryshuffle(int num_tries) {
	const int n = 10;
	int x[n];

	int hist[n][n] = {0};
	/*
		0 0 0 1 0 0 0 0 0 0

    0 0 0 0 0 0 0 0 0 0


	 */

	for (int t = 0; t < num_tries; t++) {
		for (int i = 0; i < n; i++)
			x[i] = i;
		fischeryates(x, n);
		for (int i = 0; i < n; i++)
			hist[i][x[i]]++;
	}
}
