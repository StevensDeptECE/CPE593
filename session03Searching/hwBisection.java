public class hwBisection {
  public static double bisection(FuncOneVar func, double L, double R, double eps) {
		while (   ) { 

			func.f(x)
		}	
	}

	public static void main(String[] args) {
		System.out.println(bisection(f, 1.001, 6, 0.0001));
		System.out.println(bisection(g, 0, 2, 0.000001));
		System.out.println(bisection(sin, -1, 2, 0.0001));
	}
}

interface FuncOneVar {
	public double f(double x);
}

class F implements FuncOneVar {
	public double f(double x) { return x*x - 7; }
}

class G implements FuncOneVar {
	public double f(double x) { return x*x*x - 2; }
}

class Sin implements FuncOneVar {
	public double f(double x) { return Math.sin(x); }
}


								 
