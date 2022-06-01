#include <iostream>
#include <iomanip>
using namespace std;

int fact(int n) {
    if (n <= 1)
        return 1;
    return fact(n - 1)*n;
}



double fibo(int n)
{
    static double memo[200] = {0};
    if (n<=2)
        return 1;
    if (memo[n] != 0) // remember the answer from before
        return memo[n];
    memo[n] = fibo(n-1)+fibo(n-2); //O(2^n)
    return memo[n];
}
/*

   f(10) = f(9) + f(8)
f(9) = f(8) + f(7)
f(8) = f(7)+f(6)
*/
//1,1,2,3,    5,    8
//  1 2 1.5   1.6   1.625 ...  converges on phi  =(sqrt(5)+1)/2=1.618

int main() {
    cout << setprecision(15);
   cout << fact(10) << '\n';

   cout << fact(50) << '\n';

//   cout << count(1000) << '\n';

    for (int i = 1; i <= 50; i++)
       cout << fibo(i) << '\n';   
}
