
  double lchii(x,n)
  double x;
  int n;
  { double y;
    extern double lgam2();
    if (x<0.0) x=-x;
    y=lgam2(n/2.0,x/2.0);
    return(y);
  }

