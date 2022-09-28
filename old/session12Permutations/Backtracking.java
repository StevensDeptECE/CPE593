public class Backtracking {
	private int[] p;

	public Backtracking(int n) {
		p = new int[n];
		for (int i = 0; i < n; i++)
			p[i] = i+1;
		generate(n-1);
	}

	public void doit() {
		for (int i = 0; i < p.length; i++)
			System.out.print(p[i] + " ");
		System.out.println();
	}

	private void swap(int i, int j) {
		int temp = p[i];
		p[i] = p[j];
		p[j] = temp;
	}
	
	public void generate(int n) {
		if (n == 0) {
			doit();
			return;
		}

		for (int c = 0; c <= n; c++) {
			generate(n-1);
		  swap(n % 2 != 0 ? 0 : c, n);
		}
	}


	public static void main(String[] args) {
		Backtracking b = new Backtracking(3);
	  b = new Backtracking(4);
	}

}
