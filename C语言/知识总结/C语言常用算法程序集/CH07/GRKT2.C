
  #include "stdlib.h"
  #include "math.h"
  void grkt2(t,h,y,n,eps)
  int n;
  double t,h,eps,y[];
  { extern void grkt2f();
    int m,i,j,k;
    double hh,p,dt,x,tt,q,a[4],*g,*b,*c,*d,*e;
    g=malloc(n*sizeof(double));
    b=malloc(n*sizeof(double));
    c=malloc(n*sizeof(double));
    d=malloc(n*sizeof(double));
    e=malloc(n*sizeof(double));
    hh=h; m=1; p=1.0+eps; x=t;
    for (i=0; i<=n-1; i++) c[i]=y[i];
    while (p>=eps)
      { a[0]=hh/2.0; a[1]=a[0]; a[2]=hh; a[3]=hh;
        for (i=0; i<=n-1; i++)
          { g[i]=y[i]; y[i]=c[i];}
        dt=h/m; t=x;
        for (j=0; j<=m-1; j++)
          { grkt2f(t,y,n,d);
            for (i=0; i<=n-1; i++) 
              { b[i]=y[i]; e[i]=y[i];}
            for (k=0; k<=2; k++)
              { for (i=0; i<=n-1; i++)
                  { y[i]=e[i]+a[k]*d[i];
                    b[i]=b[i]+a[k+1]*d[i]/3.0;
                  }
                tt=t+a[k];
                grkt2f(tt,y,n,d);
              }
            for (i=0; i<=n-1; i++)
              y[i]=b[i]+hh*d[i]/6.0;
            t=t+dt;
          }
        p=0.0;
        for (i=0; i<=n-1; i++)
          { q=fabs(y[i]-g[i]);
            if (q>p) p=q;
          }
        hh=hh/2.0; m=m+m;
      }
    free(g); free(b); free(c); free(d); free(e);
    return;
  }

