
import java.math.BigInteger;
import java.util.*;

public class Fermat {
	private static Random rnd = new Random(0);

	public static BigInteger powerMod(BigInteger witness, BigInteger p, BigInteger m) {
		BigInteger prod = BigInteger.ONE;
		while (!p.equals(BigInteger.ZERO)) {
			if (p.testBit(0)) {
				prod = prod.multiply(witness).mod(m);
			}

			witness = witness.multiply(witness).mod(m);
			p = p.divide(BigInteger.TWO);
		}
		return prod;
	}



	public static boolean fermatTest(BigInteger p, int k) {
		BigInteger pminus1 = p.subtract(BigInteger.ONE);
		for (int i = 0; i < k; ++i) {
			BigInteger a;
			do {
				a = new BigInteger(p.bitCount(), rnd);
			} while (a.compareTo(p) >= 0 || a.compareTo(BigInteger.ONE) <= 0);
			System.out.println(a);
			// invariant: 1 < a < p
			//			if (a.modPow(pminus1), p).compareTo(BigInteger.ONE) != 1)
			if (a.modPow(pminus1, p).compareTo(a) != 0)
			  return false;
		}
		return true;
	}

	public static void main(String[]args) {
		BigInteger a = new BigInteger("2");
		BigInteger p = new BigInteger("16");
		BigInteger pMinus1 = p.subtract(BigInteger.ONE);

		System.out.println(powerMod(a, pMinus1, p));


		a = new BigInteger("2");
		p = new BigInteger("561"); // Carmichael number, false positive
		pMinus1 = p.subtract(BigInteger.ONE);

		System.out.println(powerMod(a, pMinus1, p));

		a = new BigInteger("11"); //Factor of Carmichael number, now it will fail
		p = new BigInteger("561"); // Carmichael number, false positive
		pMinus1 = p.subtract(BigInteger.ONE);

		System.out.println(powerMod(a, pMinus1, p));


		BigInteger p1 = new BigInteger("17");
		System.out.println(fermatTest(p1, 2));

		p1 = new BigInteger("42");
		System.out.println(fermatTest(p1, 2));

		p1 = new BigInteger("60977817398996785");
		System.out.println(fermatTest(p1, 8));

		p1 = new BigInteger("609778173989967850000000000023");
		System.out.println(fermatTest(p1, 8));
	}

}
