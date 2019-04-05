#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
	vector<int> a;
	const int n = 10;
	a.reserve(n);
	for (int i = 0; i < n; i++)
		a.push_back(i);

	// only good for vector
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << '\n';

	for (vector<int>::iterator i = a.begin(); i != a.end(); ++i)
		cout << *i << ' ';
	cout << '\n';

	for (auto x : a) {
		cout << x << ' ';
	}
	cout << '\n';
	

}
