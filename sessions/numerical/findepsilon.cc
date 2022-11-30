#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double x = 1;
	// double precision is about 16 digits
	// seeeeeeeeeee then 52 bits of mantissa mmmmmmmmmm....
	// because leaing digits don't matter in hardware
	// 1.mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
	//  00000000000
	//  11111111111 = 4095-2048 = 2047
	// +/-  2^(exponent-2048)
	// 1.23456789012345E+308
	// 1.23456789012345E-308

	cout << setprecision(16);
	// 1 + x > 1
	double eps = 1;
	for (int i = 1; x + eps > x; i++, eps /= 2) {
		cout << i << ": " << (x+eps) << '\n';
	}
}
