#include<iostream>
#include <cmath>

using namespace std;

typedef double (*FuncOneVar)(double);
class Romberg{ 
private:
  FuncOneVar f;
public:
  Romberg(FuncOneVar f): f(f) {}
  
  double integral(double a, double b) {
    // hard coded but readable
    // in reality, we are adding a series of f(h/2) 
    double h = (b-a);
    double s1 = 0.5 * (f(a) + f(b));
    double s2 = s1 + f(0.5*h);
    double s4 = s2 + f(0.25*h) + f(0.75*h);
    double s8 = s4 + f(0.125*h) + f(0.375*h) + f(0.625*h) + f(0.875*h);
    
    // this shows what h is at each level, h = 1 -. 0.5 -> 0.25, ...
    // h is the distance between the bins normalized over the interval
    // so the whole interval, half of it, then every quarter
    // represents the width of the bins 
    double i1 = s1 * (h*1);
    double i2 = s2 * (h*0.5);
    double i4 = s4 * (h*0.25);
    double i8 = s8 * (h*0.125);
    
    // the error of i2 is 1/4 the error of i1, same relationship between i4 and i2, etc...
    // why that works? math   ask romberg
    double r1 = (4*i2 - i1) / 3;
    double r2 = (4*i4 - i2) / 3;
    double q1 = (16*r2 - r1) / 15;

    return q1;
  }
    
};

double function(double x) {
    return pow(x, 2);
}

int main() {

    Romberg r(function);
    cout << r.integral(0, 1) << endl;
    cout << r.integral(0, 2) << endl;
    cout << r.integral(0, 3) << endl;
    cout << r.integral(0, 4) << endl;
    cout << r.integral(0, 5) << endl;
    cout << r.integral(0, 6) << endl;
}


