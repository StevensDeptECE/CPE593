#include <iostream>
#include <string>
#include <map> // tree
#include <unordered_map> // hashmap

using namespace std;

int main() {
	map<string, double> quote;
	quote["XOM"] = 72;
	quote["AAPL"] = 181;
	quote["IBM"] = 144;

	map<string,double>::iterator i = quote.find("XOM");
	if (i == quote::end()) {
		// then it's NOT THERE
	}

	// this is NOT A CHECK if ABC exists!!!	if (quote["ABC"]) {

	}
	
	for (auto p : quote) {
		cout << p.first << ": " << p.second << '\n';
	}

	cout << "\n\n\n";
	unordered_map<string, double> quote2;
	quote2["XOM"] = 72;
	quote2["AAPL"] = 181;
	quote2["IBM"] = 144;
	for (auto p : quote2) {
		cout << p.first << ": " << p.second << '\n';
	}
}
