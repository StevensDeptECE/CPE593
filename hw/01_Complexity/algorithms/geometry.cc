#include <iostream>
#include <vector>
using namespace std;


class Point {
public:
	float x,y;
	Point(float x, float y) : x(x), y(y) {}
};

class Line {
public:
	Point p1, p2;
	static bool intersects(const Line& a, const Line& b);
};

class MinMax {
public:
	float min, float max;
	void update(double v) {
		if (v < min)
			min = v;
		if (v > max)
			max = v;
	}
	void update2(double v1, double v2) {
		if (v1 < v2) {
			if (v1 < min)
				min = v1;
			if (v2 > max)
				max = v2;
		} else {
			if (v2 < min)
				min = v2;
			if (v1 > max)
				max = v1;
		}			
	}
};

class BoundRect {
public:
	MinMax xmm, ymm;
	BoundRect(const vector<Point>& points);
	void addPoint(Point p) {
		xmm.update(p.x);
		ymm.update(p.y);
	}
	void addPoint2(Point p1, Point p2) {
		xmm.update2(p1.x, p2.x);
		ymm.update2(p1.y, p2.y);
	}
};

class BoundOct {
public:
	BoundRect rect;
	MinMax xymm, xnegymm;
	void addPoint(Point p, uint32_t i) {
		rect.addPoint(p, i);
		xymm.addPoint(p, i);
		
	}
};

class Polygon {
private:
	vector<Point> points;
public:
	Polygon() {}
	Point centroid() const;
	bool isConvex() const;
	static Polygon convexHull(const vector<Point>& points);
	BoundRect bounds() const;	
};

BoundRect::BoundRect(const vector<Point>& points) {
	if (points.size() < 2) {
		if (points.size() <= 0) {
			xmm = MinMax(0,0);
			ymm = MinMax(0,0); // TODO: this case makes no sense
		}	else {
			xmm.min = xmm.max = points[0].x;
			ymm.min = ymm.max = points[0].y;
		}
		return;
	}
	for (uint32_t i = 2; i < points.size(); i += 2) {
		xmm.addPoint2(points[0].x, points[1].x);
		ymm.addPoint2(points[0].y, points[1].y);
	}
	//TODO: complete
}

BoundRect Polygon::bounds() const {
	return BoundRect(points);
}

Point Polygon::centroid() const {
	return Point(0,0); // TODO: complete this!
}

int main() {
	ifstream f("polygon.dat");
	Polygon p;
	f >> p; // read in the polygon from the file
	cout << p.bounds() << '\n';
	cout << p.centroid() << '\n';
	
}
