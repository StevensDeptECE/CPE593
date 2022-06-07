#include <map>
#include <string>
#include <iostream>
using namespace std;

int main() {
	map<string, double> stock;
	stock["IBM"] = 119.5;
	stock["BIDU"] = 138;
	stock["AAPL"] = 152;

	for (map<string,double>::iterator i = stock.begin(); i != stock.end(); ++i)
		cout << i->first << " ==> " << i->second << '\n';
	cout << "\n\n\n";
	for (auto p : stock) {
		cout << p.first << " ==> " << p.second << '\n';
	}
	cout << '\n';
}

	
