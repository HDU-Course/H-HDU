
  #include "stdlib.h"
  #include "math.h"
  void gpbs2(t,h,n,y,eps,k,z)
  int n,k;
  double t,h,eps,y[],z[];
  { int i,j,kk,l,m,nn,it;
    void rkt2();
    double x,hh,dd,tt,q,p,g[10],*b,*d,*u,*v,*w,*e;
    b=malloc(10*n*sizeof(double));
    d=malloc(n*sizeof(double));
    u=malloc(n*sizeof(double));
    v=malloc(n*sizeof(double));
    w=malloc(n*sizeof(double));
    e=malloc(n*sizeof(double));
    for (i=0; i<=n-1; i++) z[i*k]=y[i];
    for (i=1; i<=k-1; i++)
      { for (j=0; j<=n-1; j++) v[j]=y[j];
        x=t+(i-1)*h; nn=1; hh=h; g[0]=hh;
        rkt2(x,hh,n,y,w,d,e);
        for (j=0; j<=n-1; j++)
          { b[j]=y[j]; u[j]=y[j];}
        kk=1; it=1;
        while (it==1)
          { nn=nn+nn; hh=hh/2.0; it=0;
            g[kk]=hh;
            for (j=0; j<=n-1; j++) y[j]=v[j];
            tt=x;
            for (j=0; j<=nn-1; j++)
              { rkt2(t,hh,n,y,w,d,e);
                tt=tt+hh;
              }
            for (j=0; j<=n-1; j++)
              { dd=y[j]; l=0;
                for (m=0; m<=kk-1; m++)
                  if (l==0)
                    { q=dd-b[m*n+j];
                      if (fabs(q)+1.0==1.0) l=1;
                      else dd=(g[kk]-g[m])/q;
                    }
                b[kk*n+j]=dd;
                if (l!=0) b[kk*n+j]=1.0e+35;
              }
            for (j=0; j<=n-1; j++)
              { dd=0.0;
                for (m=kk-1; m>=0; m--)
                  dd=-g[m]/(b[(m+1)*n+j]+dd);
                y[j]=dd+b[j];
              }
            p=0.0;
            for (j=0; j<=n-1; j++)
              { q=fabs(y[j]-u[j]);
                if (q>p) p=q;
              }
            if ((p>=eps)&&(kk<7))
              { for (j=0; j<=n-1; j++) u[j]=y[j];
                kk=kk+1; it=1;
              }
          }
        for (j=0; j<=n-1; j++)
          z[j*k+i]=y[j];
      }
    free(b); free(d); free(u); free(v); free(w); free(e);
    return;
  }

  static void rkt2(t,h,n,y,b,d,e)
  int n;
  double t,h,y[],b[],d[],e[];
  { extern void gpbs2f();
    int i,k;
    double a[4],tt;
    a[0]=h/2.0; a[1]=a[0]; a[2]=h; a[3]=h;
    gpbs2f(t,y,n,d);
    for (i=0; i<=n-1; i++) { b[i]=y[i]; e[i]=y[i];}
    for (k=0; k<=2; k++)
      { for (i=0; i<=n-1; i++)
          { y[i]=e[i]+a[k]*d[i];
            b[i]=b[i]+a[k+1]*d[i]/3.0;
          }
        tt=t+a[k];
        gpbs2f(tt,y,n,d);
      }
    for (i=0; i<=n-1; i++)
      y[i]=b[i]+h*d[i]/6.0;
    return;
  }

