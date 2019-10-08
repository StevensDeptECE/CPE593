class Point {
public:
  double x,y;
  Point(double x, double y) : x(x), y(y) {}
};
int main() {
  // for homework n=16
  ConvexHull ch(8); // create a 16x16 grid of GrowArray
  ch.read("convexhullpoints.dat");

  // print the biggest and smallest x
  // then the biggest and smallest y
  ch.printMinMax();
  // print the number of elements in p1,p2,p3,p4, p8,p12,p16...
  // print the external
  ch.printPerimeterClockWiseOrder();

  /*
	print the number of points in each outside grid box going in a clockwise
  direction

 In this example:
 p1,  p2,   p3,  p4,  p5,  p6, p7, p8  (top row)
 p16, p24,  p32, p40, p48, p56 (down the right side)
 p55, p54,  p53, p52, p51, p50, p49 (back along the bottom edge)
 p41, p33,  p25, p17, p9

example shown n=8
     +-----------------------------------------+
     | p1 | p2  | p3  | p4 | p5 | p6 | p7 | p8 |
     |    |     |     |    |    |    |    |    |
     +----+-----+-----+----+----+----+----+----+
     | p9 | p10 | p11 | p12| p13| p14| p15| p16|
     |    |     |     |    |    |    |    |    |
     +----+-----+-----+----+----+----+----+----+
     | p17| p18 | p19 | p20| p21| p22| p23| p24|
     |    |     |     |    |    |    |    |    |
     +----+-----+-----+----+----+----+----+----+
     | p25| p26 | p27 | p28| p29| p30| p31| p32|
     |    |     |     |    |    |    |    |    |
     +----+-----+-----+----+----+----+----+----+
     | p33| p34 | p35 | p36| p37| p38| p39| p40|
     |    |     |     |    |    |    |    |    |
     +----+-----+-----+----+----+----+----+----+
     | p41| p42 | p43 | p44| p45| p46| p47| p48|
     |    |     |     |    |    |    |    |    |
     +----+-----+-----+----+----+----+----+----+
     | p49| p50 | p51 | p52| p53| p54| p55| p56|
     |    |     |     |    |    |    |    |    |
     +----+-----+-----+----+----+----+----+----+
   */
}
