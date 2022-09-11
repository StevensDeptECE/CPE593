public class HelpMeThisIsSlow implements Benchmark {
	private int age;
	private double L, W, H;
	public String myage() {
		return "<td>" + age + "</td>";
	}
	public String length() {
		return "<td>" + L + "</td>";
	}

	public String width() {
		return "<td>" + W + "</td>";
	}
	public String height() {
		return "<td>" + H + "</td>";
	}

	public String row() {
		return "<tr>" + myage() + length() + width() + height() + "</tr>";
	}

	public String buildTable(int rows) {
		String s = "";
		for (int i = 0; i < rows; i++)
			s += row();
		return s;
	}
	public void doit(int n) {
		String s = this.buildTable(n);
	}
	
	public static void main(String[] args) {
		final int trials = 10;
		for (int n = 10000; n < 100000; n *= 2)
			Benchmarkit.benchmark(trials, n, new HelpMeThisIsSlow());
	}
}
