bool fermat(uint64_t p, int k) {
	for (int i = 0; i < k; i++) {
		a = random(2, p-1);
		if (powermod(a, p-1, p) != 1)
			return false;
	}
	return true; //probably!
}
