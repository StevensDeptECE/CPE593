#include <iostream>
using namespace std;
class Expr {
public:
	virtual Expr* simplify() const = 0;
	virtual double eval() const = 0;
	virtual void print_inorder() const = 0;
	virtual void print_preorder() const = 0;
	virtual void print_postorder() const = 0;
};

class BinOp : public Expr {

};

class Add : public BinOp {

};

class Sub : public BinOp {

};
/*
  Instructions: write classes inheriting from Expr to implement
	binary operators (+, -, *, /)
  unary functions (-, abs, sqrt, sin, cos, tan)
	constants
	variables (which have a name)

	Implement the methods above for each of your classes so the following
	code works
 */

void test(Expr* e) {
	e->print_inorder();   // print out the expression inorder, ie 1 + 2
	e->print_postorder(); // print postorder, ie 1 2 +
	e->print_preorder();  // print preorder, + 1 2
	cout << e->eval();    // print the value, Nan if unknown
	Expr* simp = e->simplify(); // simplify the expression
	simp->print_inorder();
}

int main() {
	// this expression should evaluate to 3
	// this expression should simplify to the constant 3
	Expr* e1 = new Add(new Const(1), new Const(2));
	
	Expr* e2 = new Add(new Mult(new Const(6.5), new Var("x")),
										 new Mult(new Const(4.2), new Const(2.1)));

	test(e1);
	test(e2);

	Expr* e3 = new Mult(new Add(new Var("x"), new Const(2)),
											new Sub(new Var("x"), new Const(2)));

	//optional: should simplify to 5.5x
	//evaluates to 11
	Expr* e4 = new Add(new Mult(new Const(2), new Var("x")),
										 new Mult(new Const(3.5), new Var("x")));
	e4->setVar("x", 2);
	test(e3);

	Expr* e10 = parse_postorder("5 6 + 2 x * *");
	test(e10);
	Expr* e11 = parse_postorder("5 x cos *");
	test(e11);
}
