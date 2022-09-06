#include <iostream>
#include <cmath>
using namespace std;

double f(double x) { return x*x; }

/*
	1   1   2    3     5        8       13 21 34 55
      1   2   1.5   1.66666   1.6     ...          1.618...


 */

const double phi =  (sqrt(5) +1) / 2;
const double invphi = 1.0 / phi;
template<typename FuncOneVar>
double goldenMeanSearch(FuncOneVar f, double L, double R, double eps) {
	double x1,x2;
  double y1, y2;

	
	double S = (R-L) * invphi;
	x1 = R - S, x2 = L + S;
	y1 = f(x1), y2 = f(x2);

	do {
		cout << "L=" << L << " R=" << R << " x1=" << x1 << " x2=" << x2 << '\n';
		if (y1 < y2) {
			R = x2;
			x2 = x1;
			y2 = y1;
			S = (R-L) * invphi;
			x1 = R - S;
			y1 = f(x1);
		} else {
			L = x1;
			x1 = x2;
			y1 = y2;
			S = (R-L) * invphi;
			x2 = L + S;
			y2 = f(x2);
		}
	} while ( R-L > eps);
	return y1 < y2 ? x1 : x2;
}

int main() {
	goldenMeanSearch(f, -4, 10, .0001);

}
