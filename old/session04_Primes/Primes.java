
public class Primes {
    public boolean bruteForceIsPrime(long n) {
	for (long i = 2; i < n; i++) //O(n)
	    if (n % i == 0)
		return false; // omega(1)
	return true; //O(n)
    }

    // n=10^12 sqrt(n) = 10^6
    public boolean bruteForceIsPrime2(long n) { // case 9
	for (long i = 2; i <= Math.sqrt(n); i++) //O(sqrt(n))
	    if (n % i == 0)
		return false; // omega(1)
	return true; //O(n)
    }

    //O(n*sqrt(n))  n=10^9 sqrt(n) = 10^4.5 == 33000
    public int countPrimes(long n) {
	int count = 0;
	for (long i = 2; i <= n; i++)  //O(n)
	    if (bruteForceIsPrime2(i)) // O(sqrt(n))
		count++;
	return count;
    }

        // n=10^12 sqrt(n) = 10^6
    public boolean bruteForceButTrickier(long n) { // case 9
	for (long i = 3; i <= Math.sqrt(n); i += 2) //O(sqrt(n))
	    if (n % i == 0)
		return false; // omega(1)
	return true; //O(n)
    }

    public int countPrimes2(long n) {
	int count = 1; // 2 is prime, special case
	for (long i = 3; i <= n; i += 2)  //O(n)
	    if (bruteForceIsPrime2(i)) // O(sqrt(n))
		count++;
	return count;
    }

    
    public static void main(String[]args) {
	//	System.out.println(bruteForceIsPrime(10000000000000001));
	System.out.println(bruteForceIsPrime2(10000000000000001));
    }

}
