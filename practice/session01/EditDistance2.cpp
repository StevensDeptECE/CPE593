//what if u are not allowed to take a replace operation
#include<iostream>
#include<cmath>

using namespace std;

int main() {
  string s = "AABCE";
  string t = "ACBCE";
  int m = s.length(), n = t.length();
  int dp[m + 1][n + 1];
  for(int i = 0; i <= m; i++) {
    for(int j = 0; j <= n; j++) {
      if(i == 0 || j == 0) dp[i][j] = i + j;
      else if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];
      else dp[i][j] = min(dp[i - 1][j - 1] + 2, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
    }
  }
  cout << dp[m][n] << endl;
  return 0;
}
