public class Recursive2023 {

	static long memo[] = new long[400];
	static {
		memo[1] = 1;
		memo[2] = 1;
	}
	
	public static long fibo(int n) { // Recursive2023.fibo
		if (memo[n] != 0)
			return memo[n];
		return memo[n] = fibo(n-1) + fibo(n-2);
	}

	
	public static void main(String[] args) {
		for (int n = 1; n <= 30; n++)
		System.out.println(fibo(n));
	}
}
