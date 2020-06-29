
  #include "stdlib.h"
  #include "math.h"
  void gmrsn(t,h,n,y,eps,k,z)
  int n,k;
  double t,h,eps,y[],z[];
  { extern void gmrsnf();
    int i,j,m,nn;
    double aa,bb,x,hh,p,dt,t0,qq,*a,*b,*c,*d,*u,*v;
    a=malloc(n*sizeof(double));
    b=malloc(n*sizeof(double));
    c=malloc(n*sizeof(double));
    d=malloc(n*sizeof(double));
    u=malloc(n*sizeof(double));
    v=malloc(n*sizeof(double));
    aa=t;
    for (i=0; i<=n-1; i++) z[i*k]=y[i];
    for (i=1; i<=k-1; i++)
      { x=aa+(i-1)*h; nn=1; hh=h;
        for (j=0; j<=n-1; j++) u[j]=y[j];
        p=1.0+eps;
        while (p>=eps)
          { for (j=0; j<=n-1; j++)
              { v[j]=y[j]; y[j]=u[j];}
            dt=h/nn; t=x;
            for (m=0; m<=nn-1; m++)
              { gmrsnf(t,y,n,d);
                for (j=0; j<=n-1; j++)
                  { a[j]=d[j]; y[j]=y[j]+hh*d[j]/3.0;}
                t0=t+hh/3.0;
                gmrsnf(t0,y,n,d);
                for (j=0; j<=n-1; j++)
                  { b[j]=d[j]; y[j]=y[j]+hh*(d[j]-a[j])/6.0;}
                gmrsnf(t0,y,n,d);
                for (j=0; j<=n-1; j++)
                  { b[j]=d[j];
                    bb=(d[j]-4.0*(b[j]+a[j]/4.0)/9.0)/8.0;
                    y[j]=y[j]+3.0*hh*bb;
                  }
                t0=t+hh/2.0;
                gmrsnf(t0,y,n,d);
                for (j=0; j<=n-1; j++)
                  { c[j]=d[j];
                    qq=d[j]-15.0*(b[j]-a[j]/5.0)/16.0;
                    y[j]=y[j]+2.0*hh*qq;
                  }
                t0=t+hh;
                gmrsnf(t0,y,n,d);
                for (j=0; j<=n-1; j++)
                  { qq=c[j]-9.0*(b[j]-2.0*a[j]/9.0)/8.0;
                    qq=d[j]-8.0*qq;
                    y[j]=y[j]+hh*qq/6.0;
                  }
                t=t+dt;
              }
            p=0.0;
            for (j=0; j<=n-1; j++)
              { qq=fabs(y[j]-v[j]);
                if (qq>p) p=qq;
              }
            hh=hh/2.0; nn=nn+nn;
          }
        for (j=0; j<=n-1; j++) z[j*k+i]=y[j];
      }
    free(a); free(b); free(c); free(d); free(u); free(v);
    return;
  }

