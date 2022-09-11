import java.util.*;
public class HelpMeThisIsSlow2 implements Benchmark {
	public void doit(int n) {
		ArrayList<Integer> mylist = new ArrayList<>();
		for (int i = 0; i < n; i++)
			mylist.add(i);
		for (int i = 0; i < n; i++)
			mylist.set(i, mylist.get(i) + 1);
	}
	public static void main(String[] args) {
		final int trials = 10;
		for (int n = 1000000; n <= 100000000; n *= 10)
			Benchmarkit.benchmark(trials, n, new HelpMeThisIsSlow2());
	}
}
