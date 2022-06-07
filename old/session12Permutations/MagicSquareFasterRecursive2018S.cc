#include <iostream>
using namespace std;

/*
	s[0]  s[1]  s[2]
	s[3]  s[4]  s[5]
	s[6]  s[7]  s[8]
 */
class MagicSquare {
private:
	int n;
	int* s;
	int N;


	/*n=3


  	 5  1 9

	*/
	bool check(int pos) {
    if (pos == N)
			return true;
		for (int i = pos+1; i <= N; i++)
			if (s[pos] == s[i])
				return false;
    

	}
	void generate(int pos) {
		if (pos == 0) {
			print();
			return;
		}
		for (int i = 1; i <= N; i++) {
			s[pos] = i;
      if (check(pos))
				generate(pos-1);
		}
	}
public:
	MagicSquare(int n) : n(n), s(new int[n*n]) {
		for (int i = 0; i < n*n; i++)
			s[i] = i+1;
		generate(n*n-1);
	}
	

};


int main() {
	MagicSquare m(6);
}
