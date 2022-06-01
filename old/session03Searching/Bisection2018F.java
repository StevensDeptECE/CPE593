interface FuncOneVar {
  public double f(double x);
}

class F1 implements FuncOneVar {
  public double f(double x) { return x*x - 2; }
}

public class Bisection2018F {
  public static double bisection(FuncOneVar func, double a, double b, double eps) {
		double y1 = func.f(a), y2 = func.f(b);
		double x;
		do {
			x = (a + b) / 2;
			double y = func.f(x);
			if (y > 0)
				b = x;
			else if (y < 0)
				a = x;
			else
				return x;

		} while (b - a > eps);
		return x;
	}

}
