int main() {
	int n = 3;
	int rowsum = n * (n*n+1) / 2; // 15
	
	for (int a = 1; a <= 9; a++) {
		if (int b = 1; b <= 9; b++) {
			if (a == b)
				continue;
			if (a+b > rowsum - 1)
				continue;
			if (a + b < rowsum - 9)
				continue;
			
