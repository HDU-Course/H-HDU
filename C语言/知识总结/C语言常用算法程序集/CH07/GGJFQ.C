
  #include "stdlib.h"
  #include "math.h"
  void ggjfq(t,h,n,y,eps,k,z)
  int n,k;
  double t,h,eps,y[],z[];
  { extern void ggjfqf();
    void rkt3();
    int i,j;
    double a,qq,*d,*p,*u,*v,*w;
    d=malloc(n*sizeof(double));
    p=malloc(n*sizeof(double));
    u=malloc(n*sizeof(double));
    v=malloc(n*sizeof(double));
    w=malloc(n*sizeof(double));
    for (i=0; i<=n-1; i++) {p[i]=0.0; z[i*k]=y[i];}
    a=t;
    ggjfqf(t,y,n,d);
    for (j=0; j<=n-1; j++) u[j]=d[j];
    rkt3(t,h,y,n,eps);
    t=a+h;
    ggjfqf(t,y,n,d);
    for (j=0; j<=n-1; j++)
      { z[j*k+1]=y[j]; v[j]=d[j];}
    for (j=0; j<=n-1; j++)
      { p[j]=-4.0*z[j*k+1]+5.0*z[j*k]+2.0*h*(2.0*v[j]+u[j]);
        y[j]=p[j];
      }
    t=a+2.0*h;
    ggjfqf(t,y,n,d);
    for (j=0; j<=n-1; j++)
      { qq=2.0*h*(d[j]-2.0*v[j]-2.0*u[j])/3.0;
        qq=qq+4.0*z[j*k+1]-3.0*z[j*k];
        z[j*k+2]=(p[j]+qq)/2.0;
        y[j]=z[j*k+2];
      }
    for (i=3; i<=k-1; i++)
      { t=a+(i-1)*h;
        ggjfqf(t,y,n,d);
        for (j=0; j<=n-1; j++)
          { u[j]=v[j]; v[j]=d[j];}
        for (j=0; j<=n-1; j++)
          { qq=-4.0*z[j*k+i-1]+5.0*z[j*k+i-2];
            p[j]=qq+2.0*h*(2.0*v[j]+u[j]);
            y[j]=p[j];
          }
        t=t+h;
        ggjfqf(t,y,n,d);
        for (j=0; j<=n-1; j++)
          { qq=2.0*h*(d[j]-2.0*v[j]-2.0*u[j])/3.0;
            qq=qq+4.0*z[j*k+i-1]-3.0*z[j*k+i-2];
            y[j]=(p[j]+qq)/2.0;
            z[j*k+i]=y[j];
          }
      }
    free(d); free(p); free(u); free(v); free(w);
    return;
  }


  static void rkt3(t,h,y,n,eps)
  int n;
  double t,h,eps,y[];
  { extern void ggjfqf();
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
          { ggjfqf(t,y,n,d);
            for (i=0; i<=n-1; i++) 
              { b[i]=y[i]; e[i]=y[i];}
            for (k=0; k<=2; k++)
              { for (i=0; i<=n-1; i++)
                  { y[i]=e[i]+a[k]*d[i];
                    b[i]=b[i]+a[k+1]*d[i]/3.0;
                  }
                tt=t+a[k];
                ggjfqf(tt,y,n,d);
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