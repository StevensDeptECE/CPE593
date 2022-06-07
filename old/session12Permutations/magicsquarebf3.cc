int main() {
	int n = 3;
	int rowsum = n * (n*n+1) / 2; // 15
	uint64_t used;
	for (int a = 1; a <= 9; a++) {
        used = 1 << a; // 000000100
		for (int b = rowsum-a-9; b <= min(rowsum-a-1, 9); b++) {
            if (used & (1 << b))
                continue;
            used |= (1 << b); // now it's used
			int c = rowsum - a - b;
            if (used & (1 << c))
              continue;
            used |= (1 << c);


            used &= ~(1 <<b) | (1 <<c);
        }
    }
}
			
