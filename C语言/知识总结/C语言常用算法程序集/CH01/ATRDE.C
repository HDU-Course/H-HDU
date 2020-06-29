
  #include "math.h"
  #include "stdio.h"
  int atrde(b,n,m,d)
  int n,m;
  double b[],d[];
  { int k,j;
    double s;
    if (m!=(3*n-2))
      { printf("err\n"); return(-2);}
    for (k=0;k<=n-2;k++)
      { j=3*k; s=b[j];
        if (fabs(s)+1.0==1.0)
          { printf("fail\n"); return(0);}
        b[j+1]=b[j+1]/s;
        d[k]=d[k]/s;
        b[j+3]=b[j+3]-b[j+2]*b[j+1];
        d[k+1]=d[k+1]-b[j+2]*d[k];
      }
    s=b[3*n-3];
    if (fabs(s)+1.0==1.0)
      { printf("fail\n"); return(0);}
    d[n-1]=d[n-1]/s;
    for (k=n-2;k>=0;k--)
      d[k]=d[k]-b[3*k+1]*d[k+1];
    return(2);
  }

