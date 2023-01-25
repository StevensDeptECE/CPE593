public class choose {
    public static void main(String[] args) {
      final long num_trials = 10000;
      //    final long num_trials = 1000'000;
    final int nmax = 100, rmax = 50;
    double sum = 0;
    
    for (int i = 0; i < num_trials; i++) {
        for (int n = 1; n <= nmax; n++) {
            for (int r = 1; r <= rmax; r++))
               sum += choose(n , r)

    }
    System.out.println(sum);
}