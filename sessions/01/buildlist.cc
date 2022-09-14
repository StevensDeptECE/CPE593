int main() {
	constexpr uint32_t n = 100000000;
	vector<int> a; // start with 1 double to 2 double 4
	a.reserve(n); // twice as fast!
	for (int i = 0; i < n; i++)
		a.push_back(i);
}
