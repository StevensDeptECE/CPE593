#include <iostream>
#include <iomanip>

using namespace std;

double f1(double x) { return x*x - 3; }

// .1
// .01
// .001
// .111
template<typename FuncOneVar>
double bisection(FuncOneVar f, double a, double b, double eps) {
	double ya = f(a), yb = f(b);
	if (ya * yb > 0)
		throw "function does not bracket zero!";
	double x,y;
	do {
		x = (a + b) * 0.5;
		cout << x << '\n';
		y = f(x);
		if (y < 0) {
			a = x;
		} else if (y > 0) {
			b = x;
		} else {
			return x;
		}
	} while (abs(b-a) > eps  );
	return x;
}

double f1p(double x) { return 2*x; }

template<typename FuncOneVar>
double newton(FuncOneVar f, FuncOneVar fprime, double xnext, double eps) {
	double x;
	do {
		x = xnext;
		xnext = x - f(x)/fprime(x);
    cout << x << '\n';
	} while (abs(xnext - x) > eps );
	return xnext;
}

// 1.732
int main() {
	cout << setprecision(16);

	cout << bisection(f1, 0, 5, .01) << '\n';
	cout << bisection(f1, 0, 5, .0001) << '\n';
	cout << bisection(f1, 0, 5, .00000000001) << '\n';
	cout << bisection(f1, 0, 5, .00000000001) << '\n';

	cout << newton(f1, f1p, 5, .00000000001) << '\n';
}
