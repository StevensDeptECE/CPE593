boyermoore(const char search[], const char target[]) {
	uint32_t jumps[256];
	uint32_t n = strlen(search);
	uint32_t k = strlen(target);
	for (int i = 0; i < 256; i++)
		jumps[i] = k;
	for (int i = 0; s[i] != '\0'; i++) {
		jumps[i] = k-1 - i;
	}

	for (uint32_t si = k; si < n; ) {
		uint32_t delta = jumps[ search[si]];
		if (delta == 0) {
			//maybe we found it!
			// check backwards...
		}
		si += delta;
	}
