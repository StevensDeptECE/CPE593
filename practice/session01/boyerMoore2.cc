#include <iostream>
#include <vector>

int boyerMoore(const string& s, const string& t) {
  int m = s.size(), n = t.size();
  vector<int> map(128, n);
  for(int i = n - 1; i >= 0; i--) {
    if(map[t[i]] == n) 
      map[t[i]] = n - 1 - i;
  }
  int i = n - 1;
  while(i < m) {
    for(int j = n - 1; j >= 0; j--) {
      if(j == 0 && s[i - j] == t[j]) return i - n + 1;
      if(s[i - j] == t[j]) continue;
      i += map[s[i - j]];
    }
  }
  return -1;
}
