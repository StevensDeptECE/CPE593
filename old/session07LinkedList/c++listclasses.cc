#include <vector> // dynamic array
#include <list>   // linked list
#include <iostream>

using namespace std;

int main() {
    vector<int> a;
    const int n = 1000000;
    a.reserve(n);
    for (int i = 0; i < n; i++)
      a.push_back(i);

    for (vector<int>::const_iterator i = a.begin(); i != a.end(); ++i)
      cout << *i;
    cout << '\n';
    for (vector<int>::iterator i = a.begin(); i != a.end(); ++i)
      *i *= 2;
    for (auto v : a) {
        cout << v << ' ';
    }
    cout << '\n';

    list<int> a;
    const int n = 1000000;
    for (int i = 0; i < n; i++)
      a.push_back(i);
    for (list<int>::const_iterator i = a.begin(); i != a.end(); ++i)
      cout << *i;
    cout << '\n';
    for (list<int>::iterator i = a.begin(); i != a.end(); ++i)
      *i *= 2;
    for (auto v : a) {
        cout << v << ' ';
    }
    cout << '\n';
    for (auto& v : a) {
        cout << v << ' ';
    }

}