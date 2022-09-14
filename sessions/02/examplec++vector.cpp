#include <iostream>
#include <vector>

int main() {
    constexpr int n = 1000000;
    vector<int> a;
    a.reserve(n);
    for (int i = 0; i < n; i++)
      a.push_back(i);
}