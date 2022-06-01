// choose(n,r) = n! / (r! (n-r)!)
// 52C6 = 52!/(6!46!) = 52*51*50*49*48*47 / 6*5*4*3*2*1 =
// 52C1 , 52C26

/*
      1        (0C0)
    1   1    (1C0) (1C1)
  1   2   1  (2C0)  (2C1)  (2C2)
1  3    3   1
1    6      1




 */
int main() {
	
	cout << choose(n,r) << '\n' // nCr // O(n/2) = O(n)

		// choose(52,1), choose(52, 26), choose(52, 26), //

		// n < 500, r < n 500x500 = 25,000

		//choose(52,10), choose(52,15), choose(52, 20)
		// choose(52, 12)

		memo[n][r] = answers;

	return memo[n][r];

}
