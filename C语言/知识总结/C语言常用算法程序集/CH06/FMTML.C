
  #include "stdlib.h"
  #include "math.h"
  double fmtml(n,a,b)
  int n;
  double a[],b[];
  { int m,i;
    double r,s,d,*x;
    extern double mrnd1();
    extern double fmtmlf();
    x=malloc(n*sizeof(double));
    r=1.0; d=10000.0; s=0.0;
    for (m=0; m<=9999; m++)
      { for (i=0; i<=n-1; i++)
          x[i]=a[i]+(b[i]-a[i])*mrnd1(&r);
        s=s+fmtmlf(n,x)/d;
      }
    for (i=0; i<=n-1; i++)
      s=s*(b[i]-a[i]);
    free(x); return(s);
  }

