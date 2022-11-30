#include <iostream>
#include <iomanip>
#include <cmath>

double sq(double x) { return x*x; }

double var1(const double x[], uint32_t n) {
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += x[i];
	const double mean = sum / n;
	sum = 0;
	for (int i = 0; i < n; i++)
		sum += sq(x[i] - mean);
	return sum / n;
}

// fast but not numerically stable
double var2(const double x[], uint32_t n) {
	double sumx = 0, sumxx = 0;
	for (int i = 0; i < n; i++)
		sumx += x[i], sumxx += x[i]*x[i];
  return (sumxx - sumx*sumx/n) / n;
}

//https://en.wikipedia.org/wiki/Algorithms_for_calculating_variance
double var3(const double x[], uint32_t n) {
	return 0; // TODO
}
