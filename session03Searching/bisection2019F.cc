#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
	return x*x - 2; // when x = +sqrt(2) and -sqrt(2), f(x) = 0
}

typedef double (*FuncOneVar)(double x);

double bisection(FuncOneVar f, double a, double b, double eps) {
	double ya = f(a), yb = f(b);
  if (ya*yb > 0) {
		throw "Not sure there is a root, dying!";
	}
 	// definitely crosses zero! one positive, the other negative

	if (ya > 0) {
		swap(a, b);
	}
	// definitely ya < 0 and yb > 0
  double g;
	int count = 0;
	do {
    g = (a+b)/2;
		double yg = f(g);
		if (yg > 0)
			b = g;
		else if (yg < 0)
			a = g;
		else
			return g;

	} while (count++ < 60 && abs(b-a) > eps);
	return g;
}

//  double = 57 bits of mantissa, 11 bits exponent
// 1.23456789012345 e+308
int main() {
	cout << setprecision(15);
	cout << bisection(f, 0.0, 3.0, 0.0001) << '\n'; // 
	cout << bisection(f, 0.0, 3.0, 0.00000001) << '\n'; // 
	cout << bisection(f, 0.0, 1e300, 0.00000001) << '\n'; // 
}
