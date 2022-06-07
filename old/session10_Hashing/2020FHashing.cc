#include <iostream>
#include <map> // RB-tree
#include <unordered_map> // hashing

int main() {
    map<string,double> quote;

    quote["MSFT"] = 208.22;
    quote["AAPL"] = 159.62;
    quote["IBM"] = 175.22;
    for (auto p : quote ) {
        cout << p.first << "=>" p.second << '\n';
    }
    auto i = quote.find("IBM");  //map<string,double>::iterator
    if (i != quote.end()) {
        cout << i.second; // print the value
    }

    unordered_map<string,double>quote2;
    quote2["MSFT"] = 208.22;
    quote2["AAPL"] = 159.62;
    quote2["IBM"] = 175.22;

    cout << quote2.at("IBM") << '\n';
    for (auto p : quote2 ) {
        cout << p.first << "=>" p.second << '\n';
    }
    auto i2 = quote2.find("IBM");  //unordered_map<string,double>::iterator
    if (i2 != quote2.end()) {
        cout << i.second; // print the value
    }


}