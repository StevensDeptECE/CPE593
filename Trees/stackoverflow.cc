#include <iostream>
using namespace std;

int count(int c) {
	if (c == 0)
		return 0;
	return 1 + count(c-1);
}

int main() { // 4,440,000
	cout << count(5) << '\n';
	int x[10000];
	cout << "x\n";
	int y[100000];
	cout << "y\n";
	int z[1000000]; // 4000000 is too much, crashes 2000000 works
	cout << "z\n";
	//	int w[10000000];
	//	cout << "w\n";
}
