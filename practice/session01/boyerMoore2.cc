#include <iostream>
#include <vector>

using namespace std;

int boyerMoore(const string& s, const string& t) {
  int m = s.size(), n = t.size();
  vector<int> map(128, n);
  for(int i = n - 1; i >= 0; i--) {
    if(map[t[i]] == n) 
      map[t[i]] = n - 1 - i;
  }
  int i = n - 1;
  while(i < m) {
    int j = n - 1;
    for(; j >= 0; j--) {
      if(j == 0 && s[i - j] == t[j]) return i;
      if(s[i - j] == t[j]) continue;
    }
    i += map[s[i - j]];
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
