
  #include "stdlib.h"
  #include "math.h"
  void gtnr1(t,h,n,y)
  int n;
  double t,h,y[];
  { extern void gtnr1f();
    int j;
    double s,aa,bb,dd,g,dy,dy1,*d,*p,*w,*q,*r;
    w=malloc(4*n*sizeof(double));
    q=malloc(4*n*sizeof(double));
    r=malloc(4*n*sizeof(double));
    d=malloc(n*sizeof(double));
    p=malloc(n*sizeof(double));
    for (j=0; j<=n-1; j++) w[j]=y[j];
    gtnr1f(t,y,n,d);
    for (j=0; j<=n-1; j++)
      { q[j]=d[j]; y[j]=w[j]+h*d[j]/2.0;
        w[n+j]=y[j];
      }
    s=t+h/2.0;
    gtnr1f(s,y,n,d);
    for (j=0; j<=n-1; j++)
      { q[n+j]=d[j];
        y[j]=w[j]+h*d[j]/2.0;
        w[n+n+j]=y[j];
      }
    gtnr1f(s,y,n,d);
    for (j=0; j<=n-1; j++) q[n+n+j]=d[j];
    for (j=0; j<=n-1; j++)
      { aa=q[n+n+j]-q[n+j];
        bb=w[n+n+j]-w[n+j];
        if (-aa*bb*h>0.0)
          { p[j]=-aa/bb; dd=-p[j]*h;
            r[j]=exp(dd);
            r[n+j]=(r[j]-1.0)/dd;
            r[n+n+j]=(r[n+j]-1.0)/dd;
            r[3*n+j]=(r[n+n+j]-1.0)/dd;
          }
        else p[j]=0.0;
        if (p[j]<=0.0) g=q[n+n+j];
        else
          { g=2.0*(q[n+n+j]-q[j])*r[n+n+j];
            g=g+(q[j]-q[n+j])*r[n+j]+q[n+j];
          }
        w[3*n+j]=w[j]+g*h;
        y[j]=w[3*n+j];
      }
    s=t+h;
    gtnr1f(s,y,n,d);
    for (j=0; j<=n-1; j++) q[3*n+j]=d[j];
    for (j=0; j<=n-1; j++)
      { if (p[j]<=0.0)
          { dy=q[j]+2.0*(q[n+j]+q[n+n+j]);
            dy=(dy+q[n+n+n+j])*h/6.0;
          }
        else
          { dy=-3.0*(q[j]+p[j]*w[j])+2.0*(q[n+j]
                          +p[j]*w[n+j]);
            dy=dy+2.0*(q[n+n+j]+p[j]*w[n+n+j]);
            dy=dy-(q[n+n+n+j]+p[j]*w[n+n+n+j]);
            dy=dy*r[n+n+j]+q[j]*r[n+j];
            dy1=q[j]-q[n+j]-q[n+n+j]+q[n+n+n+j];
            dy1=dy1+(w[j]-w[n+j]-w[n+n+j]+w[n+n+n+j])*p[j];
            dy=(dy+4.0*dy1*r[n+n+n+j])*h;
          }
        y[j]=w[j]+dy;
      }
    free(d); free(p); free(w); free(q); free(r);
    return;
  }

