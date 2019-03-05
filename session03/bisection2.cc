#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

long double f1(long double x) { return x*x - 2; }  // +/- sqrt(2)

typedef long double (*FuncOneVar)(long double x);

long double bisection(FuncOneVar f, long double a, long double b, long double eps) {
	long double ya = f(a);
	long double yb = f(b);
	if (ya * yb > 0)
		throw "Function does not appear to cross zero\n";
	long double mid;
	do {
		mid = (a + b) / 2;
		long double y = f(mid);
		if (y > 0)
			b = mid;
		else if (y < 0)
			a = mid;
		else
			return mid;
	} while (b - a > eps);
	return mid;
}

int main() {
	cout << bisection(f1, 0, 3, .01) << '\n';
	cout << setprecision(30);
	cout << bisection(f1, 0, 3, .0001) << '\n';
	cout << bisection(f1, 0, 3, .000001) << '\n';
	cout << bisection(f1, 0, 3, 1e-28L) << '\n';
}
	
