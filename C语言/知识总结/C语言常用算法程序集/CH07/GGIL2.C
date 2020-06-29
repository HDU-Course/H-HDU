
  #include "stdlib.h"
  #include "math.h"
  void ggil2(t,h,y,n,eps,k,z)
  int n,k;
  double t,h,eps,y[],z[];
  { extern void ggil2f();
    int i,j,m,kk,ii;
    double aa,hh,x,p,dt,r,s,t0,qq,*g,*q,*d,*u,*v;
    static double a[4]={0.5,0.29289321881,
                        1.7071067812,0.166666667};
    static double b[4]={2.0,1.0,1.0,2.0};
    static double c[4],e[4]={0.5,0.5,1.0,1.0};
    q=malloc(n*sizeof(double));
    g=malloc(n*sizeof(double));
    d=malloc(n*sizeof(double));
    u=malloc(n*sizeof(double));
    v=malloc(n*sizeof(double));
    for (i=0; i<=2; i++) c[i]=a[i];
    c[3]=0.5;
    aa=t;
    for (i=0; i<=n-1; i++) 
      { z[i*k]=y[i]; q[i]=0.0;}
    for (i=2; i<=k; i++)
      { x=aa+(i-2)*h; m=1; hh=h;
        p=1.0+eps;
        for (j=0; j<=n-1; j++) u[j]=y[j];
        while (p>=eps)
          { for (j=0; j<=n-1; j++)
              { v[j]=y[j]; y[j]=u[j]; g[j]=q[j];}
            dt=h/m; t=x;
            for (kk=0; kk<=m-1; kk++)
              { ggil2f(t,y,n,d);
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
                    ggil2f(t0,y,n,d);
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
        for (j=0; j<=n-1; j++)
          { q[j]=g[j]; z[j*k+i-1]=y[j];}
      }
    free(q); free(g); free(d); free(u); free(v);
    return;
  }

