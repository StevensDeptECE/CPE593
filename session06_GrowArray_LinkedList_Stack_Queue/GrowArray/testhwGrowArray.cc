#include "GrowArray.cc"

int main() {
	GrowArray<int> a;
	const int n = 10000000;
	for (int i = 0; i < n; i++)
		a.addEnd(i);
	cout << a.size();
}
