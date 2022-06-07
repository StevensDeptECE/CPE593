int main() {
	const int n = 4;
	//	int board[n];
	for (int a = 0; a < n; a++) {
    for (int b = 0; b < n; b++) {
			if (a == b || abs(a-b) == 1) {
				continue;
			}
			for (int c = 0; c < n; c++) {
				if (c == a || c == b || abs(c-a) == 2 || abs(c-b) == 1)
					continue;
				for (int d = 0; d < n; d++) {
					if (/*exercise for the student!*/)
						continue;
					
				}
			}
			
		}
		
	}

}
