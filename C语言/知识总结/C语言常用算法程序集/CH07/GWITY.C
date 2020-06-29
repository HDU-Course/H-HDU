
  #include "stdlib.h"
  void gwity(t,y,n,h,k,z)
  int n,k;
  double t,h,y[],z[];
  { extern void gwityf();
    int i,j;
    double x,*a,*d;
    a=malloc(n*sizeof(double));
    d=malloc(n*sizeof(double));
    for (i=0; i<=n-1; i++) z[i*k]=y[i];
    gwityf(t,y,n,d);
    for (j=1; j<=k-1; j++)
      { for (i=0; i<=n-1; i++)
          a[i]=z[i*k+j-1]+h*d[i]/2.0;
        x=t+(j-0.5)*h;
        gwityf(x,a,n,y);
        for (i=0; i<=n-1; i++)
          { d[i]=2.0*y[i]-d[i];
            z[i*k+j]=z[i*k+j-1]+h*y[i];
          }
      }
    free(a); free(d);
    return;
  }

