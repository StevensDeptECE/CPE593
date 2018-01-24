#include <iostream>
#include <vector>
using namespace std;

int boyerMoore(const string s, const string t) {
    vector<int> map(128, -1);
    int m = s.size(), n = t.size();
    for(int i = 0; i < n; i++) map[t[i]] = i;
    int i = n - 1;
    while(i < m) {
        for(int j = 0; j < n; j++) {
            if(j == n - 1 && s[i - j] == t[n - 1 - j]) return i - n + 1;
            if(s[i - j] == t[n - 1 - j]) continue;
            i = map[s[i - j]] == -1 ? i - j + n : i + n - map[s[i - j]] - 1;
            break;
        }
    }
    return -1;
}
int main() {
    string s = "here is a simple example";
    string t = "simple";
    int res = boyerMoore(s, t);
    cout << res << endl;
    return 0;
}
