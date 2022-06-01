#include <iostream>
using namespace std;

double fibo(int n) {
	static double memo[100] = {0};
	if (n <= 2)
		return 1;
	if (memo[n] != 0)
		return memo[n];
	return memo[n] = fibo(n-1)+fibo(n-2);
}

int main(int argc, char* argv[]) {
	int n = atoi(argv[1]); // fibo(10)=fibo(9)+fibo(8)  fibo(9)=fibo(8)+fibo(7)
	cout << fibo(n) << '\n';
	return 0;
}
