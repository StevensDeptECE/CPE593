#include <iostream>
using namespace std;

uint32_t maxIterations = 0;
uint32_t theNumber = 0;

void max3nplus1(uint32_t n) {
	uint32_t* p = new uint32_t[n+1];
	for (int i = 0; i <= n; i++)
		p[i] = 0;
	for (int i = 2; i <= n; i++) {
		uint32_t j = i;
		uint32_t count = 0;
		while (j > 1) {
			if (p[i] != 0) {
				count = p[i];
				break;
			}
			j = j % 2 == 0 ? j / 2 : j*3 + 1;
			count++;
		}
		if (count > maxIterations) {
			maxIterations = count;
			theNumber = j;
		}
	}
}





fastPrimeSquaresplus20(uint64_t a, uint64_t b) {
  uint32_t aa = sqrt(a - 20), bb = sqrt(b-20);

	for (uint32_t i = aa|1; i <= bb; i += 2) {
    
	}
	for (uint32_t i = a; i<=b; i++)
		int j = sqrt(i-20);

}

class Interval {
public:
	int first, second;
};

template<typename T, typename Key>
void sort(T x[], Key T::*p, uint32_t n) {
	for (int i = 0; i < n-1; i++)
		for (int j = 0; j < n-1; j++)
			if (x[j].*p > x[j+1].*p)
				swap(x[j], x[j+1]);

}

sortAndMergeIntervals(vector< Interval >& intervals) {
  sort(intervals, &Interval::first);
	int j = 0;
	for (int i = 1; i < intervals.size(); i++) { //O(n) compact an array
		if (intervals[j].second < intervals[i].first)
			j++;
		else { // [8,10], [9, 11]
			intervals[j].second = intervals[i].second; // [8,11]
		}
  }
	j++;
}


void listcompactionexample() {
	vector<int> a = {1, 3, 4, 7, 6, 9, 3, 8, 5, 4, 3, 11};
//                 ji
// [1 3 
//
int j = 0;
 for (int i = 0; i < list.size(); i++) { //O(n)
  if (a[j]%2 != 0)
		j++;
	else
		a[j++] = a[i];
}
 a.resize(j);



}


class Rect {
public:
	int x, y, w, h;
	Rect(int x, int y, int w, int h) : x(x), y(y), w(w), h(h){}
};

void rectangles() {
	int x, y, w, h;
	vector<Rect> rects;
	sort(rects, &Rect::x);
	
	while (cin >> x >> y >> w >> h) {
		rects.push_back(rect(x, y, w, h));
	}

	for (int i = 0; i < rects.size(); i++)//O(n)
		for (int j = i+1; j < rects.size(); j++) //O(n)
			if (rects[i].intersects(rects[j])) {
				count++;
			}

  // find out xmin, xmax, ymin, ymax
	// Build a grid, split rectangles
	// for each grid location, check against intersection with other retangles in the grid
	vector<Rect>* grid[16][16];

	
}

/*
    x   x   x

      x   x
     x xxxx
    x  x x
    x x x 
  x
x    x               x
x
x x
x x x                   x
 x x   x
x x x

 */


triangleContainment(Triangles t[], uint32_t n, Points[] p, int k) {
	uint32_t count = 0;
  for (uint32_t i = 0; i < k; i++) {
		for (uint32_t j = 0; j < n; j++)
			if (triangles[j].contains(p[i]))
				count++;
	}
	return count;
}

void stringFilter(const string& s) {
  bool found[256] = {false};
	for (int i = 0; i < s.length(); i++)
		if (!found[s[i]]) {
			cout << s[i];
			found[s[i]] = true;
		}

	for (int i = 0; i < s.length(); i++) //O(n^2)
		for (int j = 0; j < i; j++) { 
			if (s[i] == s[j])
				continue; // already seen it
			cout << s[i];
		}			
}
