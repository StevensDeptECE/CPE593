#include <iostream>
#include <cmath>

double (*FuncOneVar)(double);
constexpr double phi = (1 + sqrt(5))/2;

double golden_mean(FuncOneVar f, double L, double R, double eps) {
  double S = (R-L)/phi;
	double a = R - S;
	double b = L + S;
  double ya = f(a), yb = f(b);

	while (abs(R-L) > eps) {
		if (ya > yb) {
			R = b;
			S = (R-L)/phi;
			b = a;
			a = R - S;
		} else {
			L = a;
			S = (R-L)/phi;
			a = b;
			b = L + S;
		}
	}
	return ya > yb ? xa : xb;
}
