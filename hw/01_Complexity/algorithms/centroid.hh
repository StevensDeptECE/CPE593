template<typename Precision>
Point centroid(Precision x[], Precision y[], int numPoints){
  Precision signedArea = 0;
  Precision cx = 0, cy = 0;
  float seg;
  float cxseg;
  float cyseg; 
  //f << "i" << "\t" << "x[i]" << "\t" << "y[i]" << "\t" << "seg" << "\t" << "cxseg" << "\t" << "cyseg" << "\n";
  int i;
  for (i = 0; i < numPoints-1; i++) {
    seg = (x[i] * y[i+1] - x[i+1] * y[i]);
    signedArea += seg;
    cxseg = (x[i] + x[i+1]) * seg;
    cyseg = (y[i] + y[i+1]) * seg;
    cx += cxseg;
    cy += cyseg;
    //f << i << "\t" << x[i] << "\t" << y[i] << "\t" << seg << "\t" << cxseg << "\t" << cyseg << '\n';
  }
  seg = (x[i] * y[0] - x[0] * y[i]);
  signedArea += seg;
  cxseg = (x[i] + x[0]) * seg;
  cyseg = (y[i] + y[0]) * seg;
  cx += cxseg;
  cy += cyseg;
  //f << i << "\t" << x[i] << "\t" << y[i] << "\t" << seg << "\t" << cxseg << "\t" << cyseg << '\n';
  signedArea /= 2;
  //f << "signedArea: " << seg << "\tcx=" << cx << "\tcy=" << cy << std::endl;
  cx /= 6*signedArea;
  cy /= 6*signedArea;
  //f << "centroid: cx=" << cx << "\t cy=" << cy << std::endl;
  return Point(cx, cy);
}
