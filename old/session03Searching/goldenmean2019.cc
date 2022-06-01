#include <iostream>
#include <cmath>
using namespace std;

const double PHI = (sqrt(5)+1)/2;
int goldenMeanSearch(int x[], int L, int R) {
	int s = (R-L+1)/PHI;
	int GR = L + s;
	int GL = R - s;
	do {
		if (x[GR] > x[GL]) {
			L = GL;
			GL = GR
			s = (R-L+1)/PHI; //13/1.618 = 8
      GR = L + s;
		} else {
			R = GR;
			GR = GL;
			s = (R-L+1)/PHI; //13/1.618 = 8
			GL = R - s;
		}
	} while (R-L > 2);
	// now do one final computation
	// x[L]  x[GL] x[GR] x[R]
	return max(x[L], x[GL], x[GR], x[R]);
}

int main() {
	int x[] = {1, 2, 3, 99, 100, 101, 102, 102, 102, 216, 220, 238, 3};
	cout << goldenMeanSearch(x, 0, sizeof(x)/sizeof(int)-1) << '\n';
}
