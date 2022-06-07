#include <iostream>
#include <cmath>
using namespace std;
double f1(double x) {
    return x*x - 3;
}

typedef double (*FuncOneVar)(double);

double bisection(FuncOneVar f, double a, double b, double eps) {
  double x;

  do {
      x = (a+b)/2;
      double y = f(x);
        cout << "a=" << a << " b=" << b << " x=" << x << '\n';
      if (y > 0)
        b = x;
      else if (y < 0)
        a = x;
      else
        return x;
  } while (abs(a-b)> eps);
  return x;

}


int main() {
    cout << bisection(f1, 0, 5, 0.000001) << '\n';
}