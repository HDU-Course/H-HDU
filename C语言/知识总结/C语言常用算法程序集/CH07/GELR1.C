
  #include "stdlib.h"
  void gelr1(t,y,n,h,k,z)
  int n,k;
  double t,h,y[],z[];
  { extern void gelr1f();
    int i,j;
    double x,*d;
    d=malloc(n*sizeof(double));
    for (i=0; i<=n-1; i++) z[i*k]=y[i];
    for (j=1; j<=k-1; j++)
      { x=t+(j-1)*h;
        gelr1f(x,y,n,d);
        for (i=0; i<=n-1; i++)
          y[i]=z[i*k+j-1]+h*d[i];
        x=t+j*h;
        gelr1f(x,y,n,d);
        for (i=0; i<=n-1; i++)
          d[i]=z[i*k+j-1]+h*d[i];
        for (i=0; i<=n-1; i++)
          { y[i]=(y[i]+d[i])/2.0;
            z[i*k+j]=y[i];
          }
      }
    free(d); return;
  }

