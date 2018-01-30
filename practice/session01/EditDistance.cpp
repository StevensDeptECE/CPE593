/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

I will update the answer next monday.
*/
#include<iostream>
#include<cmath>
using namespace std;
int main() {
  string s = "ABCAB";
  string t = "ABCC";
  int m = s.size();
  int n = t.size();
  int dp[m + 1][n + 1];
  for(int i = 0; i <= m; i++) {
    for(int j = 0; j <= n; j++) {
      if(i == 0 || j == 0) {
	dp[i][j] = i > j? i : j;
	continue;
      }
      if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];
      else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;  
    }
  }
  cout << dp[m][n] << endl;
  return 0;
}
