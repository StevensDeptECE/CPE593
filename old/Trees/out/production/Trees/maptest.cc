#include <iostream>
#include <map>
using namespace std;

int main() {
	map<string, int> dict;
	dict["IBM"] = 1;
	dict["AAPL"] = 2;
	dict["X"] = 3;
	dict["MSFT"] = 4;

	for (map<string, int>::iterator i = dict.begin(); i != dict.end(); ++i)
		cout << i->first << "\t==>\t" << i->second << '\n';
}
