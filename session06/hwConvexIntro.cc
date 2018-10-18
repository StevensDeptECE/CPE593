class Point {
public:
  double x,y;
  Point(double x, double y) : x(x), y(y) {}
};
int main() {
  // for homework n=16
  ConvexHull ch(16); // create a 16x16 grid of GrowArray
  ch.read("convexhullpoints.dat");
  ch.printAllListSizes(); // tell us how many are in each list
  ch.printMinMax(); // print minx, maxx, miny, maxy for the entire dataset
  ch.printPerimeterClockWiseOrder(); // p1,p2,p3,p4, p8,p12,p16...
	// for each growarray around the perimeter print xmin, xmax, ymin,ymax
	// this is the minimum, maximum for the x,y in THAT BOX
  /*
example shown n=4
     -----------------------
     | p1 | p2  | p3  | p4 |
     |    |     |     |    |
     +----+-----+-----+----+
     | p5 | p6  | p7  | p8 |
     |    |     |     |    |
     +----+-----+-----+----+
     | p9 | p10 | p11 | p12|
     |    |     |     |    |
     +----+-----+-----+----+
     | p13| p14 | p15 | p16|
     |    |     |     |    |
     +----+-----+-----+----+
   */
}
