#include <iostream>
#include <string>
#include <map> // rb tree
#include <unordered_map>

using namespace std;

int main() {
	unordered_map<string, double> myMap;
	myMap["AAPL"] = 147;
	myMap["IBM"] = 118;
	myMap["X"] = 62;
	myMap["JPM"] = 105;

	cout << myMap["AAPL"] << '\n'; //O(1)

	for (unordered_map<string, double>::iterator i = myMap.begin(); i != myMap.end(); ++i)
		cout << i->first << "==>" << i->second << '\n';
}
			 
