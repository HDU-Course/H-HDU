
  double lerrf(x)
  double x;
  { double y;
    extern double lgam2();
    if (x>=0.0)
      y=lgam2(0.5,x*x);
    else
      y=-lgam2(0.5,x*x);
    return(y);
  }

