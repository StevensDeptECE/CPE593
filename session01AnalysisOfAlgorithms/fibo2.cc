#include <iostream>
using namespace std;

/*
1,1,2,3,5,8,13,21,34,55, ...
  1,2,1.5,1.6  ,.. phi = (sqrt(5)+1)/2 = 1.618
fibo(30) = fibo(29) + fibo(28)

2^10 = 1024
2^20 = 10^6
2^30 = 10^9
2^40 = 10^12
O(2^n)
*/

int fibo(uint_32t n) {
	static uint32_t memo[500] = {0};
	
	if (n <= 2)
		return 1;
	if (memo[n] != 0)
		return memo[n];
	return memo[n] = fibo(n-1) + fibo(n-2);
}
