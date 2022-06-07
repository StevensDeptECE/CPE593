public class PermuteRecursive {
	//	private int N; // the size of the problem
	private final  int[] x; // N = x.length
	PermuteRecursive(int[] x) {
            this.x = x;
            generate(x.length-1);
	}
	private final void exch(int i, int j) {
            int temp = x[i];
            x[i] = x[j];
            x[j] = temp;
	}
  final	public void generate(int n) {
            if (n == 0) {
                doit();
                return;
            }
                for (int c = 0; c <= n; c++) {
                    exch(c, n);
                    generate(n-1);
                    exch(c, n);
                }
	}
	final public void doit() {
		for (int i = 0; i < x.length; i++)
			System.out.print(x[i]);
		System.out.println();
	}
	public static void main(String[] args) {
		int[] a = {1, 2, 3, 4};
		PermuteRecursive p = new PermuteRecursive(a);
	}
}
