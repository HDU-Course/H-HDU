
  #include "math.h"
  void ontrt(x,y,n,u,v)
  int n;
  double x,y,u[],v[];
  { int k;
    double r,q,t;
    if (n<1) return;
    q=atan2(y,x);
    r=sqrt(x*x+y*y);
    if (r+1.0!=1.0)
      { r=(1.0/n)*log(r); r=exp(r);}
    for (k=0; k<=n-1; k++)
      { t=(2.0*k*3.1415926+q)/n;
        u[k]=r*cos(t); v[k]=r*sin(t);
      }
    return;
  }

