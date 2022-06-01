#include <iostream>
#include <vector>
#include <algorithm>

//https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html

using namespace std;

int main() {
    int x[] = {1, 2, 3};
    do {
        for (int i = 0; i < 3; i++)
            cout << x[i] << ' ';
        cout << '\n';
    } while (std::next_permutation(x, x+3));

    cout << "\n\n\n";
    vector<int> a = {1, 2, 3};
    do {
        for (int i = 0; i < 3; i++)
            cout << a[i] << ' ';
        cout << '\n';
    } while (std::next_permutation(a.begin(), a.end()));
    uint64_t val = 123400000617LL;
    int v = __builtin_popcountll (val);
    cout << v << '\n';
    return 0;
}