/** 
 ** Original mandel.c   by Eric R. Weeks   written 9-28-96
 **  weeks@physics.emory.edu
 **  http://www.physics.emory.edu/~weeks/
 **  
 ** cleaned up code into streamlined C++ Dov Kruger
 ** Note: the color seems completely wrong, and if I redo it all then 
 ** I will remove original Weeks reference as it becomes different.
 **  to compile:  g++ -o mand mandel.cc
 ** 
 **/

#include <cstdint>
#include <iostream>
#include <cmath>
#include <cstdlib>
void color(int red, int green, int blue)  {
	//	fputc((char)red,stdout);
	//	fputc((char)green,stdout);
	//	fputc((char)blue,stdout);
}

void mandel(uint32_t w, uint32_t h,
						uint32_t counts[], // each pixel value is the time
						double magnify,
						const int itermax) {
	magnify *= 3;
	const double invdy = 1.0 / h, invdx = 1.0 / w;
	uint32_t c = 0;
	for (int hy = 1; hy <= h; hy++)  {
		const double cy = (((float)hy) * invdy - 0.5) * magnify;
		for (int hx = 1; hx <= w; hx++)  {
			const double cx = (((float)hx) * invdx - 0.5) * magnify - 0.7;
			double x = 0.0, y = 0.0;
			int iteration;
			for (iteration = 1; iteration < itermax; iteration++) {
				double xx = x*x-y*y+cx;
				y = 2.0 * x * y + cy;
				x = xx;
				if (x*x + y*y > 2) {
					counts[c++] = iteration;
					goto next;
				}
			}
			counts[c++] = iteration;
			next:;
		}
	}
}

int main(int argc, char* argv[]) {
	const int w = 500, h = 500; // resolution of image
	const double magnify = 1.0;		/* no magnification		*/
	constexpr int itermax = 100;		// maximum number of iterations
	uint32_t* counts = new uint32_t[w*h];
	mandel(w, h, counts, magnify, itermax);

	delete [] counts;
	/* header for PPM output */
	//	printf("P6\n# CREATOR: Eric R Weeks / mandel program\n");
	//	printf("%d %d\n255\n",w, h);
}
