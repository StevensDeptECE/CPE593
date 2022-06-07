#include <iostream>
using namespace std;

int main() {
	//n=5
	const int n = 5;
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			if (a == b || a == b - 1 || a == b + 1)
				continue;
			for (int c = 0; c < n; c++) {
				if (c == a || c == b || c == b-1 || c == b+1 || c == a-2 ||| c == a+2)
					continue;
				for (int d = 0; d < n; d++) {
					//...
					int e = the one that is left...

}
