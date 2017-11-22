#include  <iostream>
using namespace std;


int main() {
	int n = 3;
	int rowsum = n * (n*n+1) / 2; // 15

	int bits;
	for (int a = 1; a <= 9; a++) {
		bits = 1 << a;
		if (int b = rowsum - a - 1; b <= rowsum - a - 9; b++) {
			if (a != b) {
				bits |= (1 << b);
				int c = rowsum - a - b;
				if ((bits & (1 << c)) == 0) {
					bits |= (1 << c);
					for (int d = rowsum - a - 1; d <= rowsum - a - 9; d++) {
						if ((bits & (1 << d)) == ) {
							bits |= (1 << d);
							for (int e = rowsum - a - 1; e <= rowsum - a - 9; e++) {
								if ((bits & (1 << e)) == 0) {
									bits |= (1 << e);
									int f = rowsum - d - e;
									if ((bits & (1 << f)) == 0) {
										bit |= (1 << f); // set the fth bit
										int g = rowsum - a - d;
										if ((bits & (1 << g)) == 0) {
											bit |= (1 << g); // set the fth bit
											int h = rowsum - b - e;
											if ((bits & (1 << h)) == 0) {
												bit |= (1 << h); // set the fth bit
												int i = rowsum - c - f;
												if (bits & (1 << i)) {
													if (f+g+h == rowsum && a + e + i == rowsum && c + e + f == rowsum) {
														cout << a << '\t' << b << '\t' << c << '\n'
																 << d << '\t' << e << '\t' << f << '\n'
																 << g << '\t' << h << '\t' << i << '\n'
												// IT's a magic square!!!!!!
															}
												}
												bits ^= (1 << h);
											}
											bits ^= (1 << g);
										}
										bits ^= (1 << f);
									}
									bits^= (1<<e);
								}
							bits^= (1 << d);
						}
					bits ^= (1 << c);
				}
				bits ^= (1 << b);
			}
		}
	}
}
