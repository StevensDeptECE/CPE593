#include <iostream>
#include <cmath>
using namespace std;

double f(double x) { return x*x - 7; }
double g(double x) { return x*x*x - 2; }

typedef double (*FuncOneVar)(double x);

double bisection(FuncOneVar f, double L, double R, double eps) {
	while (   ) { 
		//		y = f(x);

	}	
}
								 
int main() {
	cout << bisection(f, 1.001, 6, 0.0001) << "\n";
	cout << bisection(g, 0, 2, 0.000001) << "\n";
	cout << bisection(sin, -1, 2, 0.0001) << "\n";
}
	
