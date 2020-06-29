
  #include "math.h"
  void ocsin(x,y,u,v)
  double x,y,*u,*v;
  { double p,q;
    p=exp(y); q=exp(-y);
    *u=sin(x)*(p+q)/2.0; *v=cos(x)*(p-q)/2.0;
    return;
  }

