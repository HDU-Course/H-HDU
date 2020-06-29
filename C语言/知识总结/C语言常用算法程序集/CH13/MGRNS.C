
  #include "math.h"
  void mgrns(u,g,r,n,a)
  int n;
  double u,g,*r,a[];
  { int i,k,m;
    double s,w,v,t;
    s=65536.0; w=2053.0; v=13849.0;
    for (k=0; k<=n-1; k++)
      { t=0.0;
        for (i=1; i<=12; i++)
          { *r=(*r)*w+v; m=(int)(*r/s);
            *r=*r-m*s; t=t+(*r)/s;
          }
        a[k]=u+g*(t-6.0);
      }
    return;
  }

