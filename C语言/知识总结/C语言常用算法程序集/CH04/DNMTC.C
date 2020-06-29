
  #include "stdlib.h"
  #include "math.h"
  void dnmtc(x,n,b,m,eps)
  int n,m;
  double x[],b,eps;
  { extern double mrnd1();
    extern double dnmtcf();
    int k,i;
    double a,r,*y,z,z1;
    y=malloc(n*sizeof(double));
    a=b; k=1; r=1.0; z=dnmtcf(x,n);
    while (a>=eps)
      { for (i=0; i<=n-1; i++)
          y[i]=-a+2.0*a*mrnd1(&r)+x[i];
        z1=dnmtcf(y,n);
        k=k+1;
        if (z1>=z)
          { if (k>m) { k=1; a=a/2.0; }}
        else
          { k=1; 
            for (i=0; i<=n-1; i++) x[i]=y[i];
            z=z1;
            if (z<eps)  return;
          }
      }
    return;
  }

