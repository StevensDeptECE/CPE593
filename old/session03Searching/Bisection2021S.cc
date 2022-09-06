#include <iostream>
#include <cmath>
using namespace std;

double f(double x) { return x*x - 9; }



typedef double (*FuncOneVar)(double);
double bisection (FuncOneVar f, double a, double b, double eps) {
	// assuming that f(a) < 0 and f(b) > 0
	double mid;
	do {
		mid = (a+b)/2;
		double y = f(mid);
		if (y < 0)
			a = mid;
		else if ( y > 0)
			b = mid;
		else
			return mid;
	} while ( abs(b-a) > eps);
	return mid;
}


int main() {
	//	cout << bisection(f, 0, 2e100, .01) << '\n';

	// 3.5  2.75 3.125    1-bit accuracy more each time
	cout << bisection(f, 2, 5, .1) << '\n';
	cout << bisection(sin, -1.5, 1, .000001) << '\n';
}
