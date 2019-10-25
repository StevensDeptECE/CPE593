#include "GrowArray.hh"
#include <vector>
using namespace std;

void test1(int n) {
	GrowArray a;
	for (int i = 0; i < n; i++)
		a.insertEnd(i);
}

void test2(int n) {
	GrowArray a(n);
	for (int i = 0; i < n; i++)
		a.insertEnd(i);
}

void test3(int n) {
	vector<int> a;
	for (int i = 0; i < n; i++)
		a.push_back(i);
}

void test3(int n) {
	vector<int> a;
	a.reserve(n);
	for (int i = 0; i < n; i++)
		a.push_back(i);
}

int main() {
	const int n = 1000000000;
	test1(n);
	//	test2(n);
	//	test3(n);
}
