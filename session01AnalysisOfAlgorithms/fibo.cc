#include <iostream>
using namespace std;

// 1, 1, 2, 3, 5, 8, 13, 21, ....
// a  b  c
//    a  b  c
// a  b
//    a  b
//       a  b = 4
int fibo(int n) { // O(n)
	int a = 1,b = 1, c; // O(1)
	for (int i = 1; i <= n; i++) { // O(n)
		c = a + b; // O(1)
		cout << n << '\t' << c << '\n';
		a = b;     // O(1)
		b = c;     // O(1)
	}
	return c;
}

int main() {  // O(m*n)  --> O(m)
	const int m = 14;
	fibo(14);
	//	for (int i = 1; i <= m; i++) //O(m)
	//		cout << i << '\t' << fibo(i) << '\n';
}
