
  double lffff(f,n1,n2)
  int n1,n2;
  double f;
  { double y;
    extern double lbeta();
    if (f<0.0) f=-f;
    y=lbeta(n2/2.0,n1/2.0,n2/(n2+n1*f));
    return(y);
  }

