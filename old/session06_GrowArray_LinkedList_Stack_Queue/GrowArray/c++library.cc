#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
	const uint64_t n = atoi(argv[1]);
	vector<int> list;
	list.reserve(n);
	for (uint64_t i = 0; i < n; i++)
		list.push_back(i);

	int sum = 0;
	for (uint64_t i = 0; i < n; i++)
		sum += list[i];
	cout << sum << '\n';
}
