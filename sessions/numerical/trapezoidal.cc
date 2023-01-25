#include <iostream>
#include <iomanip>
using namespace std;

double f1(double x) { return x*x; }
double f2(double x) { return x*x*x; }
double f3(double x) { return 5* x + 3 ; } // int(f3,0, 2) 5/2x^2 + 3x  = 16

template<typename FuncOneVar>
double trapezoidal(FuncOneVar f, double a, double b, int n) {
  double sum = 0.5*(f(a) + f(b));
	double h = (b-a)/n;
	double x = a + h;
	for (int i = 1; i < n; i++, x += h)
		sum += f(x);
	return sum * h; // + error O(h^2)
}

template<typename FuncOneVar>
double trapezoidal2(FuncOneVar f, double a, double b, int n, double eps) {
  double sum = 0.5*(f(a) + f(b));
	double h = (b-a)/n;
	double h2;
	double x = a + h;
	for (int i = 1; i < n; i++, x += h)
		sum += f(x);
	double sum2 = sum - 10000;
	double temp = sum;
	do {
		h2 = h/2;
		x = a + h2; // start at center of first slice
		sum2 = sum;
		for (int i = 1; i <= n; i++, x += h)
			sum2 += f(x);
		cout << "sum2=" << sum2 << '\n';
		h = h2;
	}while (abs(sum2 - sum) > eps);
	return sum2 * h2; // + error O(h2^2)
}



int main() {
	cout << setprecision(16);
	//	for (int slices = 1; slices < 1024*1024*1024; slices *=2)
	//		cout << trapezoidal(f1, 0, 1, slices) << '\n';
	cout << trapezoidal(f2, 0, 1, 4) << '\n';
	cout << trapezoidal(f2, 0, 1, 8) << '\n';
	cout << trapezoidal(f3, 0, 2, 1) << '\n';

	cout << trapezoidal2(f2, 0, 1, 4, .000000001) << '\n';


}
