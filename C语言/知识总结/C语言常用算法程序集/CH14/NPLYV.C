
  #include "math.h"
  double nplyv(a,n,x)
  int n;
  double x,a[];
  { int i;
    double u;
    u=a[n-1];
    for (i=n-2; i>=0; i--)
      u=u*x+a[i];
    return(u);
  }

