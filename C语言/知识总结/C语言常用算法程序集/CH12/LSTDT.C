
  double lstdt(t,n)
  int n;
  double t;
  { double y;
    extern double lbeta();
    if (t<0.0) t=-t;
    y=1.0-lbeta(n/2.0,0.5,n/(n+t*t));
    return(y);
  }

