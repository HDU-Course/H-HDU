
  #include "math.h"
  double lgass(a,d,x)
  double a,d,x;
  { double y;
    extern double lerrf();
    if (d<=0.0) d=1.0e-10;
    y=0.5+0.5*lerrf((x-a)/(sqrt(2.0)*d));
    return(y);
  }

