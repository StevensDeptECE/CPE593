int main() {
	vector<int> a;
	const int n = 10;
	a.reserve(n);
	for (int i= 0; i < n; i++)
		a.push_back(i);
  for (int i = 0; i < n; i +=2) //O(n)
		a.remove(i); // O(n)

	// 0  1  2  3  4  5  6 7 8 9
	// 0  2  4  6  8
	//                j        i
	
	int j = 0;
	for (int i = 0; i < a.size(); i++) { //O(n)
		if (a[i] % 2 == 0) {
			a[j] = a[i];
			j++;
		} else {}
	}
	a.resize(j); //O(n)
