// choose(n,r) = n!/(r! (n-r)!) = 52! / (6! 46!)
// dynamic programming for choose(n,r)
double choose(int n, int r) {
  static double memo[100][100] = {0};

  if (memo[n][r] != 0)
    return memo[n][r];
  // compute the answer and store into memo
}

int main() {
  for (int i = 1; i < 1000000000; i++)
    cout << choose(52, 6) << '\n';
}
