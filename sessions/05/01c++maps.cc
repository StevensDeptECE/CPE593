#include <iostream>
#include <map>           // rbtree
#include <unordered_map> // hashmap
#include <set>
#include <string>
using namespace std;

int main() {
    map<string, double> quotes;
    quotes["AAPL"] = 148.5;
    quotes["IBM"] = 123;
    quotes["MSFT"] = 243;
    map<string, double>::iterator i = quotes.find("X");
    //auto i = quotes.find("X");
    if (i != quotes.end()) {
    cout << i->first << "==>" <<  i->second << '\n'; // key=>value
    }
    for (auto q : quotes) {
        cout << q.first << "==>" << q.second << '\n';
    }
//    set<uint32_t> myset;

}