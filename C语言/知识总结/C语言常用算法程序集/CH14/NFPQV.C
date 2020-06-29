
  #include "math.h"
  double nfpqv(x,b,n,t)
  int n;
  double x[],b[],t;
  { int k;
    double u;
    u=b[n-1];
    for (k=n-2; k>=0; k--)
      { if (fabs(u)+1.0==1.0)
           u=1.0e+35*(t-x[k])/fabs(t-x[k]);
        else
           u=b[k]+(t-x[k])/u;
      }
    return(u);
  }

