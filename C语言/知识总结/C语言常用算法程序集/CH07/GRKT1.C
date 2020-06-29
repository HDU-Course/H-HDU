
  #include "stdlib.h"
  void grkt1(t,y,n,h,k,z)
  int n,k;
  double t,h,y[],z[];
  { extern void grkt1f();
    int i,j,l;
    double a[4],tt,*b,*d;
    b=malloc(n*sizeof(double));
    d=malloc(n*sizeof(double));
    a[0]=h/2.0; a[1]=a[0];
    a[2]=h; a[3]=h;
    for (i=0; i<=n-1; i++) z[i*k]=y[i];
    for (l=1; l<=k-1; l++)
      { grkt1f(t,y,n,d);
        for (i=0; i<=n-1; i++) b[i]=y[i];
        for (j=0; j<=2; j++)
          { for (i=0; i<=n-1; i++)
              { y[i]=z[i*k+l-1]+a[j]*d[i];
                b[i]=b[i]+a[j+1]*d[i]/3.0;
              }
            tt=t+a[j];
            grkt1f(tt,y,n,d);
          }
        for (i=0; i<=n-1; i++)
          y[i]=b[i]+h*d[i]/6.0;
        for (i=0; i<=n-1; i++)
          z[i*k+l]=y[i];
        t=t+h;
      }
    free(b); free(d);
    return;
  }

