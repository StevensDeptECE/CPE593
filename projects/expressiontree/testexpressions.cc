#include "expr.hh"
void test_expr(const char ex[]) {
	expr* e = expr::parse(ex);
	e->print();
	cout << "eval: " << e->eval() << '\n';
	e->simplify();
	cout << "simplified: " << e->print();
	cout << "===========================================\n\n";
}

int main() {
	test_expr("2 3 +");
	test_expr("2 3 + 4 5 - *");
	test_expr("2 3 + 4 5 - *");
	test_expr("x 0 *"); // 0
	test_expr("x 1 *"); // x
	test_expr("x x -"); // 0
	//	test_expr("x x /"); // 1, unless x==0, so we won't do this one
	
	test_expr("x sqrt x sqrt *"); // x
	
	test_expr("x 2 * x 3 * -"); // should simplify to -x
	test_expr("x 2 * x 5 * -"); // should simplify to x * -3
	test_expr("x 2 * 3 x * +"); // should simplify to x * 5

	test_expr("x sin 2 ^ x cos 2 ^ +"); // sin^2+cos^2=1
}
