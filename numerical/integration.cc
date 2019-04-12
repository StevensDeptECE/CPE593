#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x) { return x*x; }
double g(double x) { return x*x*x; }
double h(double x) { return x*x*x*x; }

typedef double (*FuncOneVar)(double x);

double trapezoidal(FuncOneVar f, double a, double b, double eps) {
	int n = 2;
	double h = (b - a) / n;
	double avgHeight = 0.5*(f(a) + f(b)) + f((a+b)/2);
	double I2 = avgHeight * h;
	cout << "I2=" << I2 << '\n';
	n = n * 2;
	h = h * 0.5;
	double x = h; 
	for (int i = 0; i < n; i++, x += 2*h)
		avgHeight += f(x);
	double I4 = avgHeight * h;
	cout << "I4=" << I4 << '\n';
	return I4;
}




constexpr double X2 = 1/ sqrt(3);
double gauss2(FuncOneVar f, double a, double b) {
	double mid = (a + b) / 2;
	double h = (b - a) / 2;
	double x0 = mid - X2 * h;
	double x1 = mid + X2 * h;
  double y0 = f(x0);
	double y1 = f(x1);
	return y0 + y1;
}


constexpr double X3 = sqrt(3.0/ 5);
double gauss3(FuncOneVar f, double a, double b) {
	double mid = (a + b) / 2;
	double h = (b-a) / 2;
	double y0 = f(mid);
	double y1 = f(mid - X3 * h);
	double y2 = f(mid + X3 * h);
	return 8.0/9*y0 + 5.0/9*(y1+y2);
}

#if 0
// in Java
public interface FuncOneVar {
	public double f(double x);
}
#endif

int main() {
	cout << setprecision(15);
	cout << trapezoidal(f, 0, 2, 0.001) << '\n';
	cout << gauss2(f, 0, 2) << '\n'; 	// 8/3 = 2.6666666
	cout << gauss2(g, 0, 2) << '\n'; 	// 8/3 = 2.6666666

	cout << gauss2(h, 0, 2) << '\n'; 	// 1/5 x^5 = 1/5 * 32 = 32/5
	cout << gauss2(h, 0, 1) + gauss2(h, 1, 2) << '\n'; 	// 1/5 x^5 = 1/5 * 32 = 32/5
	cout << gauss3(h, 0, 2) << '\n';
}
