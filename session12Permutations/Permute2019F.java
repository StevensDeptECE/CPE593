public class Permute2019F {
	private int[] p;
	public Permute2019F(int n) {
		p = new int[n];
		for (int i = 0; i < n; i++)
			p[i] = i+1;
        generate(n-1);
	}
	public void printit() {
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
			printit();
			return;
		}
		for (int i = 0; i <= n; i++) {
			generate(n-1);
			swap(n % 2 != 0 ? 0 : i, n);
		}
	}
	public static void main(String[] args) {
		new Permute2019F(4);
	}
}
