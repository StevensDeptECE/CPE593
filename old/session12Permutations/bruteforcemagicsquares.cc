#include <iostream>
using namespace std;


/* 1 2 3
   4 5 6
   7 8 9

 */
int main() {
  for (int a = 1; a <= 9; a++) {
		for (int b = 1; b <= 9; b++) {
			if (a == b)
				continue;
			int c = 15 - a - b;
			if (c < 1 || c >9 || c == a || c == b)
				continue;
      for (int d = 1; d <= 9; d++) {
				if (d == a || d == b || d == c)
					continue;
				for (int e = 1; e <= 9; e++) {
					if (e == a || e == b || e == c || e == d)
						continue;
					int f = 15 - d - e;

					/*
						a b c
						d e f
						g h i
					 */
					if (f < 1 || f > 9 || f == a || f == b || f == c || f == d || f == e)
						continue;
					int g = 15 - a - d;
					if (g < 1 || g > 9 || g == a || g == b || g == c || g == d || g == e || g == f)
						continue;
					int h = 15 - b - e;
					int i = 15 - c - f;
					if (h < 0 || h > 9 || h == a || h == b || h == c || h == d || h == e || h == f || h == g)
						continue;
					if (i < 0 || i > 9 || i == a || i == b || i == c || i == d || i == e || i == f || i == g || i == h)
						continue;
					if (a+e+i != 15 || c + e + g != 15) // diagonals
						continue;
					cout
						 << a << ' ' << b << ' ' << c << '\n'
						 << d << ' ' << e << ' ' << f << '\n'
						 << g << ' ' << h << ' ' << i << "\n\n";
				}
			}
		}
	}
}
