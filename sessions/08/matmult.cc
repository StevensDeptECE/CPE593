/*
	row-major go across the row first (C++, Java row-major order)
	1 2 3
	4 5 6
	7 8 9

	column-major
	1 4 7
	2 5 8
	3 6 9

	// out of order is 2-3 times slower than sequential
	1  2  3  4  5  6  7  8
	9 10 11 12 13 14 15 16
	17...


	 // 3-4 (paging, MMU)
	1     2 3 ...     1024
	1025
 */

constexpr int m = 2, n = 3, p = 4;
// c = a * b
void mult(double a[m][n], double b[n][p], double c[m][p]) {
  for (int k = 0; k < m; k++) {
		for (int j = 0; j < p; j++) {
			c[k][j] = 0;
			for (int i = 0; i < n; i++)
				c[k][j] += a[k][i] * b[i][j];
		}
	}
}

// use a register to avoid writing to memory
void mult2(double a[m][n], double b[n][p], double c[m][p]) {
  for (int k = 0; k < m; k++) {
		for (int j = 0; j < p; j++) {
			double dot = 0;
			for (int i = 0; i < n; i++)
				dot += a[k][i] * b[i][j];
			dot = c[k][j];
		}
	}
}

