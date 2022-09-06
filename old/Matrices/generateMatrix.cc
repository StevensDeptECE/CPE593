#include <iostream>
#include <random>
#include <cmath>
#include  "Matrix.hh"

using namespace std;

int randomInt(int n) {
	return abs(rand() % n);
}

int main() {
	int n = abs(rand() % 7 + 3);
	ofstream f("hw5.dat");
	f << n << '\n';

	Matrix m;
	do {
		m = Matrix::random(-n, n); //O(n^2)
	} while (!m.cond()); /// O(n^3)

	/*
		1 2 -3
		1 2 3
		-2 2 1
	 */
	// guaranteed m is not ill-conditioned
	
	f << m << '\n';

	vector<double> solution;
	for (int i = 0; i < n; i++)
		solution.push_back(randomInt(-n,n));
	vector<double> B = m.mult(solution);
	for (int i = 0; i < n; i++)
		f << B[i] << ' ';
	f << '\n';
}

/*
example:
	1    2    3          2     =     1*2 + 2*-1 + 3*3 = 9
	2    1    0          -1    =     2*2 + 1*-1 + 0*3 = 3
	-1   1    2          3     =     -1*2 + 1*-1 + 2*3 = 3

output:
3
1 2 3
2 1 0
-1 1 2

9 3 3

yes


 */



	
