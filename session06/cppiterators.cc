#include<iostream>
#include<vector>
#include<list>

using namespace std;
int main() {
	vector<int> a;
	for (int i = 0; i < 10; i++)
		a.push_back(i);
	for (vector<int>::const_iterator i = a.begin(); i != a.end(); ++i)
		cout << *i;
	for (vector<int>::iterator i = a.begin(); i != a.end(); ++i)
		*i *= 2;

	for (vector<int>::reverse_iterator i = a.rbegin(); i != a.rend(); ++i)
		cout << *i;
}
