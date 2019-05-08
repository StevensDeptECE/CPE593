int main() {
	int n = 3;
	int rowsum = n * (n*n+1) / 2; // 15
	
	for (int a = 1; a <= 9; a++) {
		if (int b = rowsum-a-9; b <= rowsum-a-1; b++) {
			if (a == b)
				continue;
			int c = rowsum - a - b;
			if (c == a || c == b)
				continue;
			
