import java.util.*;

public class Benchmarkit {
	public static void benchmark(final int trials,
															 final int n,
															 Benchmark b) {
		System.out.printf("Benchmark %s trials=%d n=%d\n", b, trials, n);
		long totalTime = 0;
		for (int t = 0; t < trials; t++) {
			long t0 = System.nanoTime();
			b.doit(n);
			long t1 = System.nanoTime();
			final long elapsed = t1-t0;
			System.out.printf("%6.3f\t", elapsed * 1e-9);
			totalTime += elapsed;
		}
		System.out.println();
		System.out.printf("average=%6.3f\n", totalTime/trials*1e-9);
	}
}
