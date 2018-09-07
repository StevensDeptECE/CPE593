typedef double (*FuncOneVar)(double x);

double euler(FuncOneVar f, double a, double b, int n) {
	double h = (b-a) / n;
	double x = a;
	double sum = 0;
	for (int i = 0; i <= n; i++, x += h)
		sum +=  f(x);
	return sum * h; // error O(h)
}

double trapezoidal(FuncOneVar f, double a, double b, int n) {
	double h = (b-a) / n;
	double sum = 0.5*(f(a) + f(b));
	double x = a + h;
	for (int i = 1; i < n; i++, x += h)
		sum +=  f(x);
	return sum*h; // error O(h*h)
}

double trapezoidalQS(FuncOneVar f, double a, double b, double eps) {
	double i, inext;
	int n = 2;
	inext = trapezoidal(f, a, b, n);
	do {
		i = inext;
		n *= 2;
		inext = trapezoidal(f, a, b, n);
	} while (abs(inext - i) > eps);
	return inext;
}


double betterTrapezoidalQS(FuncOneVar f, double a, double b, double eps) {
	double i, inext;
	int n = 2;
	inext = 0.5* (f(a) + f(b)) + f((a+b)/2);
	do {
		i = inext;
		n *= 2;
		double sum = 0;
		double h = (b-a) / n;
		double x = a + h;
		for (int i = 1; i < n; i++)
			sum += f(x);
		inext = i + sum;
	} while (abs(inext - i)*h > eps);
	return inext*h;
}

double gaussQuadrature3(FuncOneVar f, double a, double b, int n) {
	double h2 = (b-a) / n; // h is 1/2 the interval
	double h = h2 / 2;

	double x = a;
	const double Xi = sqrt(3.0/5);
	const double w0 = 8.0 / 9;
	const double w1 = 5.0 / 9;
	double sum = 0;
	for (int i = 0; i < n; i++, x += h2) {
		double x0 = x + h;
		double x1 = x0 - Xi * h;
		double x2 = x0 + Xi * h;
		sum += w0 * f(x0) + w1 * (f(x1)+ f(x2));
	}
  return sum * h;
}


