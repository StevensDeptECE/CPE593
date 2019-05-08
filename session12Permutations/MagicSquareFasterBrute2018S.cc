#include <iostream>
using namespace std;

int main() {
	/* magic square n=3   N = 9, rowsum = 15
		 a b c
     d e f
     g h i



example of bigger: n = 4, N = 16,  rowsum = 34
		 a b c d
     e f g h
     i j k m
     n o p q
	*/
	const int n = 3;
	const int N = n*n;
	int rowsum = 15;
	// orig: 9**9
	// after 3rd loop: 9**6
	// 9**4


	int bits = 0;
	for (int a = 1; a <= N; a++) { //N
		bits = 1 << a;//	// 00000001 .. 00000010
		for (int b = rowsum - a - N; b <= rowsum - a - 1; b++) { //N
			if (a == b)
				continue;
			bits |= (1 << b);
			int c = rowsum - a - b; //O(1)
			if (bit & (1 << c))
				continue; // this number already used
			if (c == a || c == b) // if (bits & (1<<c))
				continue;
			for (int d = 1; d <= N; d++) {
				if (d==a || d == b || d== c)
					continue;
				int g = rowsum - a - d;
				if (g == a || g == b || g == c || g == d || g == e || g == f)
					continue;
				if (g < 1 || g > N)
					continue;
				for (int e = 1; e <= N; e++) {
					if (e == a || e == b || e == c || e == d)
						continue;
					int f = rowsum - d - e;
					if (f < 1 || f > N)
						continue;
					int h = rowsum - b - e;
					if (h < 1 || h > N)
						continue;
				
			
