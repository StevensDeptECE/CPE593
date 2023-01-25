#include <iostream>
#include <iomanip>
using namespace std;

uint64_t fact(int n) {
	if (n <= 1)
		return 1;
	return n * fact(n-1);
}

uint64_t fact2(int n) {
	uint64_t prod = 1;
	for (; n > 1; n--)
		prod *= n;
	return prod;
}
// 1   1   2    3      5      8      13  21  34  55  89 ...
//     1   2    1.5    1.6   1.625   phi
// phi = (sqrt(5)+1)/2 = 1.618...

double  fibo(int n) {
  static double memo[400] = {0};
  if (n <= 2 )
		return 1;
	if (memo[n] != 0)
		return memo[n];
	return memo[n] = fibo(n-1) + fibo(n-2);
}

int main(int argc, char* argv[]) {
	int n = atoi(argv[1]);
	uint64_t sum = 0;
	//	for (int i = 0; i < 100000000; i++)
	//	sum += fact(n);
		//		sum += fact2(n);

	//cout << sum << '\n';

	cout << setprecision(16);
	for (int n = 1; n < 100; n++)
		cout << fibo(n) << '\n';
}
