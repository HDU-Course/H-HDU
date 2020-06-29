
  #include "math.h"
  double fmtcl(a,b)
  double a,b;
  { int m;
    double r,d,x,s;
    extern double fmtclf();
    extern double mrnd1();
    r=1.0; s=0.0; d=10000.0;
    for (m=0; m<=9999; m++)
      { x=a+(b-a)*mrnd1(&r);
        s=s+fmtclf(x)/d;
      }
    s=s*(b-a);
    return(s);
  }

