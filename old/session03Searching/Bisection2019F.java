interface FuncOneVar {
	public double f(double x);
}

class F implements FuncOneVar {
	public double f(double x) {
		return x*x - 2; // roots +sqrt(2)  -sqrt(2)
	}
}

public class Bisection {
	public static double bisection(FuncOneVar func,
																 double a, double b, double eps) {
		double ya = func.f(a), yb = func.f(b);
 		if (ya * yb > 0) {
			throw new RuntimeException("There may not be a root!");
		}
		if (ya > 0) {
			double temp = a;
			a = b;
			b = temp;
		}
		// guarantee: ya < 0  yb > 0

		double mid;

		do {
			mid = (a+b)*0.5;
			double ymid = func.f(mid);
			if (ymid < 0)
				a = mid;
			else if (ymid > 0)
				b = mid;
			else
				return mid; // NEVER HAPPENS
		} while (Math.abs(b-a) > eps);
		return mid;
	}
		
	public static void main(String[] args) {
		FuncOneVar func = new F();
		System.out.println(bisection(func, 0, 2, .01));
		System.out.println(bisection(func, 0, 2, .0001));
		System.out.println(bisection(func, 0, 2, .0000000001));
		//this will never complete, double precision is not accurate enough:
		//   System.out.println(bisection(func, 0, 2, 1e-30));

		// double 1.23456789012345 = 57 bits mantissa
		// 11 bits exponent E+308
		// 1 bit sign

		// 		bisection(func, 0, 1e308, 0.01);

		// bisection improves by 1 bit each iteration

		// Newton, Ridders  quadratic  (double the bits each time)
		// 10 bit accuracy -> 20 bits -> 40 bits
				
				
	}
}
