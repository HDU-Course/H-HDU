
  #include "math.h"
  void occos(x,y,u,v)
  double x,y,*u,*v;
  { double p,q;
    p=exp(y); q=exp(-y);
    *u=cos(x)*(p+q)/2.0; *v=-sin(x)*(p-q)/2.0;
    return;
  }

