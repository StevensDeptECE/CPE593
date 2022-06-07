#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int x[] = {1, 2, 3, 4};
  char s[] = "abcd";
  vector<int> a = {1, 2, 3, 4};
	vector<string> b;
	b.push_back("abc");
	b.push_back("def");
	b.push_back("hello");

  while (std::next_permutation(x, x+4)) {
    for (auto e : x)
      cout << e;
    cout << '\n';
  }

  while (next_permutation(s, s+4)) {
    for (auto e : s)
      cout << e;
    cout << '\n';
  }
  while (next_permutation(a.begin(), a.end())) {
    for (auto e : a)
      cout << e;
    cout << '\n';
  }
}
  
