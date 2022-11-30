#include <iostream>
#include <iomanip>
using namespace std;

double f1(double x) { return x*x; }

template<typename FuncOneVar>
double trapezoidal(FuncOneVar f, double a, double b, int n) {
  double sum = 0.5*(f(a) + f(b));
	double h = (b-a)/n;
	double x = a + h;
	for (int i = 1; i < n; i++, x += h)
		sum += f(x);
	return sum * h;
}

int main() {
	cout << setprecision(16);
	for (int slices = 1; slices < 1024*1024*1024; slices *=2)
		cout << trapezoidal(f1, 0, 1, slices) << '\n';
}
