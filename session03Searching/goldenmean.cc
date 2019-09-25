double f(double x) { return 8 - x * x; }

const double PHI = (1 + sqrt(5)) /2;

double goldenMean(FuncOneVar f, double L, double R) {
	double s = (R-L) / PHI;
	double x1 = R - S;
	double x2 = L + S;
	double y1 = f(x1);
	double y2 = f(x2);
	while (  abs(R - L) > eps ) {
	if (y1 > y2) {
		R = x2;
		x2 = x1;
		y2 = y1;
		s = (R - L)/ PHI;
		x1 = R - S;
	} else if (y2 <= y1) {
		L = x1;
		x1 = x2;
		y1 = y2;
		s = (R - L) / PHI;
		x2 = L + S;
	}	
  return y1 > y2 ? x1 : x2;
}

int main() {
	cout << goldenMean(f, -3, +4);
