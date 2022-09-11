#include <vector>
#include <random>
#include <iostream>

using namespace std;

vector<int> buildlist(const int n) {
	vector<int> a;
	for (int i = 0; i < n; i++)
		a.push_front(i);
	return a;
}

vector<int> striplist(vector<int> a) {
	for (int i = 0; i < 10; i++) {
		int r = 
		a.remove(r);
	}
  for (int i = 0; i < a.size(); i++)
		a.remove(i); // remove elements 0, 2, 4, 6, ...
}
int main(int argc, char argv[]) {
	const int n = argc > 1 ? atoi(argv[1]) : 10000000;
	printlist(striplist(buildlist(n)));
}
	
