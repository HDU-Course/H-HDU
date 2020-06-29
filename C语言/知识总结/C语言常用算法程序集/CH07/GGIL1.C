
  #include "stdlib.h"
  #include "math.h"
  void ggil1(t,h,y,n,eps,q)
  int n;
  double t,h,eps,y[],q[];
  { extern void ggil1f();
    int i,j,k,m,ii;
    double x,p,hh,r,s,t0,dt,qq,*d,*u,*v,*g;
    static double a[4]={0.5,0.29289321881,
                        1.7071067812,0.166666667};
    static double b[4]={2.0,1.0,1.0,2.0};
    static double c[4],e[4]={0.5,0.5,1.0,1.0};
    d=malloc(n*sizeof(double));
    u=malloc(n*sizeof(double));
    v=malloc(n*sizeof(double));
    g=malloc(n*sizeof(double));
    for (i=0; i<=2; i++) c[i]=a[i];
    c[3]=0.5;
    x=t; p=1.0+eps; hh=h; m=1;
    for (j=0; j<=n-1; j++) u[j]=y[j];
    while (p>=eps)
      { for (j=0; j<=n-1; j++)
          { v[j]=y[j]; y[j]=u[j]; g[j]=q[j];}
        dt=h/m; t=x;
        for (k=0; k<=m-1; k++)
          { ggil1f(t,y,n,d);
            for (ii=0; ii<=3; ii++)
              { for (j=0; j<=n-1; j++)
                  d[j]=d[j]*hh;
                for (j=0; j<=n-1; j++)
                  { r=(a[ii]*(d[j]-b[ii]*g[j])+y[j])-y[j];
                    y[j]=y[j]+r;
                    s=g[j]+3.0*r;
                    g[j]=s-c[ii]*d[j];
                  }
                t0=t+e[ii]*hh;
                ggil1f(t0,y,n,d);
              }
            t=t+dt;
          }
        p=0.0;
        for (j=0; j<=n-1; j++)
          { qq=fabs(y[j]-v[j]);
            if (qq>p) p=qq;
          }
        hh=hh/2.0; m=m+m;
      }
    for (j=0; j<=n-1; j++) q[j]=g[j];
    free(g); free(d); free(u); free(v);
    return;
  }

