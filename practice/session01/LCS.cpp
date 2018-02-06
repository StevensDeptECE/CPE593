#include <iostream>
#include <cmath>
using namespace std;

int LCS(string s, string t) {
    int m = s.size();
    int n = t.size();
    int dp[m + 1][n + 1];
    for(int i = 0; i < m + 1; i++) {
        for(int j = 0; j < n + 1; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if(s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; 
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
int main() {
    string s = "here is a simple example";
    string t = "eam";
    int res = LCS(s, t);
    std::cout << res << std::endl;
    return 0;
}