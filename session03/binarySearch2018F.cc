#include <iostream>
#include <cmath>
using namespace std;

double f1(double x) { return x*x - 2; }

typedef double (*FuncOneVar)(double);

double bisection(FuncOneVar f, double a, double b, double eps) {
	double y1 = f(a), y2 = f(b);
	double x;
  do {
		x = (a + b) / 2;
		double y = f(x);
		if (y > 0)
			b = x;
		else if (y < 0)
			a = x;
		else
			return x;
	} while (b - a > eps);
	return x;
}

// how many bits in a double??? 64        seeeeeeeeeeemmmmmmmmmmmmmmmmmmmmmmmmmmm
// 1 bit sign
// 11 bit exponent
// 56 bits mantissa effective 57

int main() {
	cout << bisection(f1, 0, 3, 0.001) << '\n';
	cout << bisection(sin, 0, 5, 0.000001) << '\n';
}
