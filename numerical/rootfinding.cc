#include <iostream>
using namespace std;

double f(double x) { return x*x - 3; }
double fp(double x) { return 2*x; }

/*

  by how much does your answer improve in floating point each time?

  [0,3]
  [1.5, 3]
  [1.5, 2.25]
  
  double has 54 bits accuracy (mantissa)
*/

typedef double (*FuncOneVar)(double);
double bisection(FuncOneVar f, double a, double b, double eps) {
  double ya = f(a), yb = f(b);
  if (ya * yb > 0)
    throw "bounds do not straddle zero";
  if (ya > yb)
    swap(a,b);
  do {
    double x =  (a + b) / 2;
    double y = f(x);
    if (y < 0) {
      a = x;
    } else if (y > 0) {
      b = x;
    } else {
        return x;
    }
  } while (abs(b-a) > eps);

}

// If I have seen farther than other men it is because I was standing on the shoulders of giants.

double newtonRaphson(FuncOneVar f, FuncOneVar fprime, double x0, double eps) {

  double x;
  do {
      x = x0 - f(x0) / fp(x0);
  } while (abs(x-x0) > eps);
  return x;
}



int main() {
//    cout << bisection(f, 0, 3.2e+72, .1) << '\n';
    cout << bisection(f, 0, 3, .1) << '\n';
    cout << bisection(f, 0, 3, .01) << '\n';
    cout << bisection(f, 0, 3, .000001) << '\n';
    cout << bisection(f, 0, 3, .000000001) << '\n';
    cout << newtonRaphson(f, fp, 0, .01);
    cout << newtonRaphson(f, fp, 0, .0000000000001);

} 
