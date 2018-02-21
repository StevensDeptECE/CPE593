#include <iostream>
#include <vector>

using namespace std;

int boyerMoore(const string& s, const string& t) {
  int m = s.size(), n = t.size();
  vector<int> map(128, n);
  for(int i = 0; i < n; i++) { 
      map[t[i]] = n - 1 - i;
  }
  int i = n - 1;
  while(i < m) {
    int j = i;
    for(; j >= i - n + 1; j--) {
      if(j == i - n + 1 && s[j] == t[j - i + n - 1]) return i - n + 1;
      if(s[i - j] == t[j]) continue;
      else break;
    }
    i += map[s[j]];
  }
  return -1;
}
int main() {
    string s = "here is a very very simple example";
    string t = "simple";
    int res = boyerMoore(s, t);
    cout << res << endl;
    return 0;
}
