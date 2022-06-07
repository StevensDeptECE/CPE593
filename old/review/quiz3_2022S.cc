// from a to b inclusive
uint64_t prod(int a, int b) {
	uint64_t prod = 1;
  for (int i = a; i <= b; i++)
		prod *= i;
	return prod;
}
double mean(double x[], int len) {
  double sum = 0;

	for (int i = 0; i < len; i++)
		sum += x[i];
	return sum / len; //type promotion
}

void polar2rect(double r, double theta, double& x, double& y) {
	x = r*cos(theta);
	y = r*sin(theta);
}
	
int main() {
  uint64_t ans1 = prod(a,b);
  double arr[] = {10, 20, 30, 40};
  double avg = mean(arr, 4);
  double x, y;
  double r = 4, theta = pi/2;
  polar2rect(r, theta, x, y); // note: x and y are passed by reference
}
