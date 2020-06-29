
  #include "stdlib.h"
  #include "math.h"
  void gelr2(t,h,y,n,eps)
  int n;
  double t,h,eps,y[];
  { extern void gelr2f();
    int i,j,m;
    double hh,p,x,q,*a,*b,*c,*d;
    a=malloc(n*sizeof(double));
    b=malloc(n*sizeof(double));
    c=malloc(n*sizeof(double));
    d=malloc(n*sizeof(double));
    hh=h; m=1; p=1.0+eps;
    for (i=0; i<=n-1; i++) a[i]=y[i];
    while (p>=eps)
      { for (i=0; i<=n-1; i++)
          { b[i]=y[i]; y[i]=a[i];}
        for (j=0; j<=m-1; j++)
          { for (i=0; i<=n-1; i++) c[i]=y[i];
            x=t+j*hh;
            gelr2f(x,y,n,d);
            for (i=0; i<=n-1; i++)
              y[i]=c[i]+hh*d[i];
            x=t+(j+1)*hh;
            gelr2f(x,y,n,d);
            for (i=0; i<=n-1; i++)
              d[i]=c[i]+hh*d[i];
            for (i=0; i<=n-1; i++)
              y[i]=(y[i]+d[i])/2.0;
          }
        p=0.0;
        for (i=0; i<=n-1; i++)
          { q=fabs(y[i]-b[i]);
            if (q>p) p=q;
          }
        hh=hh/2.0; m=m+m;
      }
    free(a); free(b); free(c); free(d);
    return;
  }

