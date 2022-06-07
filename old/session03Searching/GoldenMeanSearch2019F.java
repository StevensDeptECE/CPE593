public class GoldenMeanSearch2019 {
	public final static double phi = (Math.sqrt(5) + 1) / 2; // 1.618....
	public static int goldenMean(int[] list) {
		int L = 0, R = list.length -1;
		int s = (R - L + 1) / phi; // length of the interval
		int GL, GR;
		do {
			GL = R - s;
			GR = L + s;
			if (list[GL] > list[GR]) {
				R = GR;
				GR = GL;
				s = (R - L + 1) / phi;
				GL = R - s;
			} else {
				L = GL;
				GL = GR;
				s = (R - L + 1) / phi;
				GR = L + s;
			}			 
		} while (R - L > 2);
		if (x[L] > x[R]) {
      if (x[GL] > x[L])
				return x[GL];
			else
				return x[L];
		} else {
			if (x[GR] > x[R])
				return x[GR];
			else
				return x[R];
		}

	}
	
	public static void main(String[] args) {
		int[] x = {-2, 1, 100, 101,101,101,101, 102, 119,
							 1000, 1001, 1001, 1001, 1002};
		System.out.println(goldenMean(x));
	}
}
