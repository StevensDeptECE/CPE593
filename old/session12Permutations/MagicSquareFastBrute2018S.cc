#include <iostream>
using namespace std;

int main() {
	/* magic square n=3
		 a b c
     d e f
     g h i
	*/
	const int n = 3;
	const int N = n*n;
	int rowsum = 15;
	// orig: 9**9
	// after 3rd loop: 9**6
	// 9**4
	for (int a = 1; a <= N; a++) { //N
		for (int b = 1; b <= N; b++) { //N
			if (a == b)
				continue;
			int c = rowsum - a - b; //O(1)
			if (c == a || c == b)
				continue;
			if (c < 1 || c > N)
				continue;
			for (int d = 1; d <= N; d++) {
				if (d==a || d == b || d== c)
					continue;
				int g = rowsum - a - d;
				if (g == a || g == b || g == c || g == d)
					continue;
				if (g < 1 || g > N)
					continue;
				for (int e = 1; e <= N; e++) {
					if (e == a || e == b || e == c || e == d || e == g)
						continue;
					int f = rowsum - d - e;
					if (f < 1 || f > N)
						continue;
					if (f == a || f == b || f == c || f == d || f == e || f == g)
						continue;
					int h = rowsum - b - e;
					if (h < 1 || h > N)
						continue;
					if (h == a || h == b || h == c || h == d || h == e || h == g
							|| h== f)
						continue;
				
			
