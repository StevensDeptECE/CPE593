void f(int n) {
	int a[n][n]; // NOT LEGAL
}
int main() {
		// x is stored as a single contiguous
		block of memory
		double x[3][4] = {
			{1, 2, 5, 6},
			{2, -1, 3, 8},
			{3, 1, 5, 2}
		};

		x[0][2] = 3;

		f(5);
	}
