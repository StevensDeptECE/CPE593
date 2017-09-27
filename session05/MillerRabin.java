import java.util.*;

public class MillerRabin { 
    private static Random rnd = new Random(0); // always seed with a known value for testing
    private static BigInteger TWO = new BigInteger(2);
    public static boolean millerRabin(BigInteger p, int k) {
	
	BigInteger pminus1 = p.subtract(BigInteger.ONE);
	// find out how many trailing zeros there are in p-1
	int r = pminus1.getLowestSetBit(); // r is the number of zero bits
	BigInteger d = pminus1.shiftRight(r);
	nextTrial:
	for (int i = 0; i < k; ++i) {
	    BigInteger temp;
	    BigInteger a;
	    do {   //if < 3 we have a problem
		temp = new BigInteger(pminus1.bitCount()+ 10, rnd);
		a = temp.mod(pminus1);
	    } while (a.compareTo(TWO) < 0);
	    // 1 < a < p-2
	    // compute a^d mod p
	    BigInteger x = a.modPow(d, p);
	    if (x.compareTo(BigInteger.ONE) == 0 || x.compareTo(pminus1) == 0)
		continue;
	    for (--r ; r > 0; --r) {
		x = x.modPow(TWO,p); // x^TWO mod p
		if (x.compareTo(BigInteger.ONE) == 0)
		    return false;
		if (x.compareTo(pminus1) == 0)
		    continue nextTrial;
	    }
            return false;	    
	}
        return true;
 
    }
    public static  void main(String[] args) {
	BufferedReader br = new BufferedReader(System.in);
	String digits = br.readLine();
	BigInteger p = new BigInteger(digits);
	System.out.println(millerRabin(p, 6));

    }
}
