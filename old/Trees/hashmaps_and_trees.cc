#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;


int main() {
  map<string, double> obt;
  obt["IBM"] = 123.45; // O(log(n))


  unordered_map<string, double> hm;
  hm["IBM"] = 123.45; // O( 1  )
  hm["AAPL"] = 151.45;
  hm["T"] = 29.0;

  unordered_map<string,double>::iterator i = hm.find("x");
  if (i != hm.end()) {
    double price = i->second;
  }
  for (pair<string, double> element : hm)
  {
    cout << element.first << " :: " << element.second << endl;
  }
  for (auto e : hm) {
    cout << e.first << " :: " << e.second << endl;
  }
}