
  #include "math.h"
  void opowr(x,y,n,u,v)
  int n;
  double x,y,*u,*v;
  { double r,q;
    q=atan2(y,x);
    r=sqrt(x*x+y*y);
    if (r+1.0!=1.0)
      { r=n*log(r); r=exp(r);}
    *u=r*cos(n*q); *v=r*sin(n*q);
    return;
  }

