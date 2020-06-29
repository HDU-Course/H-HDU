
  #include "stdlib.h"
  #include "math.h"
  void ghamg(t,h,n,y,eps,k,z)
  int n,k;
  double t,h,eps,y[],z[];
  { extern void ghamgf();
    void rkt5();
    int i,j,m;
    double a,q,*b,*d,*u,*v,*w,*g;
    b=malloc(4*n*sizeof(double));
    d=malloc(n*sizeof(double));
    u=malloc(n*sizeof(double));
    v=malloc(n*sizeof(double));
    w=malloc(n*sizeof(double));
    g=malloc(n*sizeof(double));
    a=t;
    for (i=0; i<=n-1; i++) z[i*k]=y[i];
    ghamgf(t,y,n,d);
    for (i=0; i<=n-1; i++) b[i]=d[i];
    for (i=1; i<=3; i++)
      if (i<=k-1)
        { t=a+i*h;
          rkt5(t,h,y,n,eps);
          for (m=0; m<=n-1; m++) z[m*k+i]=y[m];
          ghamgf(t,y,n,d);
          for (m=0; m<=n-1; m++) b[i*n+m]=d[m];
        }
    for (i=0; i<=n-1; i++) u[i]=0.0;
    for (i=4; i<=k-1; i++)
      { for (j=0; j<=n-1; j++)
          { q=2.0*b[3*n+j]-b[n+n+j]+2.0*b[n+j];
            y[j]=z[j*k+i-4]+4.0*h*q/3.0;
          }
        for (j=0; j<=n-1; j++)
          y[j]=y[j]+112.0*u[j]/121.0;
        t=a+i*h;
        ghamgf(t,y,n,d);
        for (j=0; j<=n-1; j++)
          { q=9.0*z[j*k+i-1]-z[j*k+i-3];
            q=(q+3.0*h*(d[j]+2.0*b[3*n+j]-b[n+n+j]))/8.0;
            u[j]=q-y[j];
            z[j*k+i]=q-9.0*u[j]/121.0;
            y[j]=z[j*k+i];
            b[n+j]=b[n+n+j];
            b[n+n+j]=b[n+n+n+j];
          }
        ghamgf(t,y,n,d);
        for (m=0; m<=n-1; m++) b[3*n+m]=d[m];
      }
    free(b); free(d); free(u); free(v); free(w); free(g);
    return;
  }

  static void rkt5(t,h,y,n,eps)
  int n;
  double t,h,eps,y[];
  { extern void ghamgf();
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
          { ghamgf(t,y,n,d);
            for (i=0; i<=n-1; i++) 
              { b[i]=y[i]; e[i]=y[i];}
            for (k=0; k<=2; k++)
              { for (i=0; i<=n-1; i++)
                  { y[i]=e[i]+a[k]*d[i];
                    b[i]=b[i]+a[k+1]*d[i]/3.0;
                  }
                tt=t+a[k];
                ghamgf(tt,y,n,d);
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