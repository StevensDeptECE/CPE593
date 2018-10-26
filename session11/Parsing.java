import java.util.Scanner;
import java.io.*;

abstract class Expr {
	protected Expr left, right;
  protected Expr parent;

	public void inorder();
	public void preorder();
	public void postorder();
	public double eval();
}

class Const extends Expr {
	private double val;
	
  public double eval() {  return val; }
	}
}
class Var extends Expr {
	public double eval() { return 0;}
}

//class BinaryOperation {}
class Add  {
}
class Sub {

}
class Mult {

}
class Div {

}
class Sqrt {

}
class Negate {

}

public class Parsing {
	public static void main(String[] args) throws Exception {
		// (x + 1) * (x - x)
		// x 1 + x x - *

		//   binary + - * /    unary - sqrt
		Scanner s = new Scanner(new BufferedReader(new FileReader("equations.dat")));
		String token = s.next();
	}
}
