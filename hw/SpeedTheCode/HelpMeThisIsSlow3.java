import java.util.*;
public class HelpMeThisIsSlow3 implements Benchmark {
	public void doit(int n) {
		ArrayList<Integer> mylist = new ArrayList<>();
		for (int i = 0; i < n; i++)
			mylist.add(0, i);
	}
	public String toString() {
		return "Building a list in descending order n n-1 n-2 ... 3 2 1 0";
	}
	public static void main(String[] args) {
		final int trials = 10;
		final int n = Integer.parseInt(args[0]);
		Benchmarkit.benchmark(trials, n, new HelpMeThisIsSlow3());
	}
}
