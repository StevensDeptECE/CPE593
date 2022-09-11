#include <iostream>
#include <string>

using namespace std;

uint64_t LCS(string a, string b) {
	if (a.length() == 0 || b.length() == 0)
		return 0;
  if (a[0] == b[0])
		return 1 + LCS(a.substr(1), b.substr(1));
	return max(LCS(a.substr(1), b), LCS(a, b.substr(1)));
}

int main() {
	#if 0
	{
		const string a = "this is a test";
		const string b = "why this not is the test of LCS";
		cout << LCS(a,b) << '\n';
	}
#endif
	{
		const string a = "if you thought that was bad, check this out";
		const string b = "IF YOU THOUGHT THAT WAS BAD, CHECK THIS OUT! WHOA!";
		cout << LCS(a,b) << '\n';
	}
}
