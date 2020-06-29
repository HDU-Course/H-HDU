
  #include "math.h"
  #include "stdio.h"
  int agsdl(a,b,n,x,eps)
  int n;
  double a[],b[],x[],eps;
  { int i,j,u,v;
    double p,t,s,q;
    for (i=0; i<=n-1; i++)
      { u=i*n+i; p=0.0; x[i]=0.0;
        for (j=0; j<=n-1; j++)
          if (i!=j)
            { v=i*n+j; p=p+fabs(a[v]);}
        if (p>=fabs(a[u]))
          { printf("fail\n"); return(-1);}
      }
    p=eps+1.0;
    while (p>=eps)
      { p=0.0;
        for (i=0; i<=n-1; i++)
          { t=x[i]; s=0.0;
            for (j=0; j<=n-1; j++)
              if (j!=i) s=s+a[i*n+j]*x[j];
            x[i]=(b[i]-s)/a[i*n+i];
            q=fabs(x[i]-t)/(1.0+fabs(x[i]));
            if (q>p) p=q;
          }
      }
    return(1);
  }

