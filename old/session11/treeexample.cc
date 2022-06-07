#include <map>
//#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
  map<string, double> prices;
  prices["MSFT"] = 66;
  prices["IBM"] = 170;
  prices["AAPL"] = 150;

  cout << prices["AAPL"] << "\n";

  for (map<string,double>::iterator i = prices.begin(); i != prices.end(); ++i) {
    cout << i->first << "==>" << i->second << '\n';
  }
}
