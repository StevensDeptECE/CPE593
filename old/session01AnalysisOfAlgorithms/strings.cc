#include <iostream>
#include <string>
using namespace std;

int LCS(string a, string b) {
    static int memo[1000][1000];
  if (a.length() == 0 || b.length() == 0)
    return 0;
  if (a[0] == b[0])
    return 1 + LCS(a.substr(1), b.substr(1));
  return max(LCS(a.substr(1), b), LCS(a, b.substr(1)));
}

#if 0
// your turn
int LCS(const char a[], const char b[]) {

    LCS(a+1, b+1) // use pointers...

}


// your turn
int LCS(const char a[], const char b[], int m, int n) {

    LCS(a+m, b+n) // use pointers...

}
#endif




int main() {
  string s1 = "hello";
  string s2 = "ohell"; //LCS(s1,s2)=4

  //cout << find(s1, s2);

 
  cout << LCS(s1, s2) << '\n';

  string s3 = "thyiysy iys ya tyeyst";
  string s4 = "txhxixsx xixsx xax very long txexsxxxxxxt"; ///"this is a test"
  cout << LCS(s3, s4) << '\n';

    
}