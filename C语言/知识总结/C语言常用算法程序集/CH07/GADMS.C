
  #include "stdlib.h"
  #include "math.h"
  void gadms(t,h,n,y,eps,k,z)
  int n,k;
  double t,h,eps,y[],z[];
  { extern void gadmsf();
    void rkt4();
    int i,j,m;
    double a,q,*b,*e,*s,*g,*d;
    b=malloc(4*n*sizeof(double));
    e=malloc(n*sizeof(double));
    s=malloc(n*sizeof(double));
    g=malloc(n*sizeof(double));
    d=malloc(n*sizeof(double));
    a=t;
    for (i=0; i<=n-1; i++) z[i*k]=y[i];
    gadmsf(t,y,n,d);
    for (i=0; i<=n-1; i++) b[i]=d[i];
    for (i=1; i<=3; i++)
      if (i<=k-1)
        { t=a+i*h;
          rkt4(t,h,y,n,eps);
          for (j=0; j<=n-1; j++) z[j*k+i]=y[j];
          gadmsf(t,y,n,d);
          for (j=0; j<=n-1; j++) b[i*n+j]=d[j];
        }
    for (i=4; i<=k-1; i++)
      { for (j=0; j<=n-1; j++)
          { q=55.0*b[3*n+j]-59.0*b[2*n+j];
            q=q+37.0*b[n+j]-9.0*b[j];
            y[j]=z[j*k+i-1]+h*q/24.0;
            b[j]=b[n+j];
            b[n+j]=b[n+n+j];
            b[n+n+j]=b[n+n+n+j];
          }
        t=a+i*h;
        gadmsf(t,y,n,d);
        for (m=0; m<=n-1; m++) b[n+n+n+m]=d[m];
        for (j=0; j<=n-1; j++)
          { q=9.0*b[3*n+j]+19.0*b[n+n+j]-5.0*b[n+j]+b[j];
            y[j]=z[j*k+i-1]+h*q/24.0;
            z[j*k+i]=y[j];
          }
        gadmsf(t,y,n,d);
        for (m=0; m<=n-1; m++) b[3*n+m]=d[m];
      }
    free(b); free(e); free(s); free(g); free(d);
    return;
  }


  static void rkt4(t,h,y,n,eps)
  int n;
  double t,h,eps,y[];
  { extern void gadmsf();
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
          { gadmsf(t,y,n,d);
            for (i=0; i<=n-1; i++) 
              { b[i]=y[i]; e[i]=y[i];}
            for (k=0; k<=2; k++)
              { for (i=0; i<=n-1; i++)
                  { y[i]=e[i]+a[k]*d[i];
                    b[i]=b[i]+a[k+1]*d[i]/3.0;
                  }
                tt=t+a[k];
                gadmsf(tt,y,n,d);
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