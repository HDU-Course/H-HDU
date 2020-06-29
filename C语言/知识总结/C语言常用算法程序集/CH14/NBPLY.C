
  #include "math.h"
  double nbply(a,m,n,x,y)
  int m,n;
  double a[],x,y;
  { int i,j;
    double u,s,xx;
    u=0.0; xx=1.0;
    for (i=0; i<=m-1; i++)
      { s=a[i*n+n-1]*xx;
        for (j=n-2; j>=0; j--)
          s=s*y+a[i*n+j]*xx;
        u=u+s; xx=xx*x;
      }
    return(u);
  }

