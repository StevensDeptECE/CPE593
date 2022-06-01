#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> a;
	for (int i = 0; i < 10; i++)
		a.push_back(i);
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << ' ';
	cout << '\n';

	for (vector<int>::iterator i = a.begin(); i != a.end(); ++i) {
    cout << *i << ' ';
	}

	for (auto x : a) {
		cout << x;
	}

	
