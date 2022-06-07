public interface FuncOneVar {
  public double f(double x);
}

public class F1 implements FuncOneVar {
	public double f(double x) { return x*x - 2; }
}

double bisection(FuncOneVar func, ...) {

	//func.f(x)

}
