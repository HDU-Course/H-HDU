
  #include "stdlib.h"
  int klman(n,m,k,f,q,r,h,y,x,p,g)
  int n,m,k;
  double f[],q[],r[],h[],y[],x[],p[],g[];
  { int i,j,kk,ii,l,jj,js;
    double *e,*a,*b;
    extern int brinv();
    e=malloc(m*m*sizeof(double));
    l=m;
    if (l<n) l=n;
    a=malloc(l*l*sizeof(double));
    b=malloc(l*l*sizeof(double));
    for (i=0; i<=n-1; i++)
      for (j=0; j<=n-1; j++)
        { ii=i*l+j; a[ii]=0.0;
          for (kk=0; kk<=n-1; kk++)
            a[ii]=a[ii]+p[i*n+kk]*f[j*n+kk];
        }
    for (i=0; i<=n-1; i++)
      for (j=0; j<=n-1; j++)
        { ii=i*n+j; p[ii]=q[ii];
          for (kk=0; kk<=n-1; kk++)
            p[ii]=p[ii]+f[i*n+kk]*a[kk*l+j];
        }
    for (ii=2; ii<=k; ii++)
      { for (i=0; i<=n-1; i++)
        for (j=0; j<=m-1; j++)
          { jj=i*l+j; a[jj]=0.0;
            for (kk=0; kk<=n-1; kk++)
              a[jj]=a[jj]+p[i*n+kk]*h[j*n+kk];
          }
        for (i=0; i<=m-1; i++)
        for (j=0; j<=m-1; j++)
          { jj=i*m+j; e[jj]=r[jj];
            for (kk=0; kk<=n-1; kk++)
              e[jj]=e[jj]+h[i*n+kk]*a[kk*l+j];
          }
        js=brinv(e,m);
        if (js==0) 
          { free(e); free(a); free(b); return(js);}
        for (i=0; i<=n-1; i++)
        for (j=0; j<=m-1; j++)
          { jj=i*m+j; g[jj]=0.0;
            for (kk=0; kk<=m-1; kk++)
              g[jj]=g[jj]+a[i*l+kk]*e[j*m+kk];
          }
        for (i=0; i<=n-1; i++)
          { jj=(ii-1)*n+i; x[jj]=0.0;
            for (j=0; j<=n-1; j++)
              x[jj]=x[jj]+f[i*n+j]*x[(ii-2)*n+j];
          }
        for (i=0; i<=m-1; i++)
          { jj=i*l; b[jj]=y[(ii-1)*m+i];
            for (j=0; j<=n-1; j++)
              b[jj]=b[jj]-h[i*n+j]*x[(ii-1)*n+j];
          }
        for (i=0; i<=n-1; i++)
          { jj=(ii-1)*n+i;
            for (j=0; j<=m-1; j++)
              x[jj]=x[jj]+g[i*m+j]*b[j*l];
          }
        if (ii<k)
          { for (i=0; i<=n-1; i++)
            for (j=0; j<=n-1; j++)
              { jj=i*l+j; a[jj]=0.0;
                for (kk=0; kk<=m-1; kk++)
                  a[jj]=a[jj]-g[i*m+kk]*h[kk*n+j];
                if (i==j) a[jj]=1.0+a[jj];
              }
            for (i=0; i<=n-1; i++)
            for (j=0; j<=n-1; j++)
              { jj=i*l+j; b[jj]=0.0;
                for (kk=0; kk<=n-1; kk++)
                  b[jj]=b[jj]+a[i*l+kk]*p[kk*n+j];
              }
            for (i=0; i<=n-1; i++)
            for (j=0; j<=n-1; j++)
              { jj=i*l+j; a[jj]=0.0;
                for (kk=0; kk<=n-1; kk++)
                  a[jj]=a[jj]+b[i*l+kk]*f[j*n+kk];
              }
            for (i=0; i<=n-1; i++)
            for (j=0; j<=n-1; j++)
              { jj=i*n+j; p[jj]=q[jj];
                for (kk=0; kk<=n-1; kk++)
                  p[jj]=p[jj]+f[i*n+kk]*a[j*l+kk];
              }
          }
      }
    free(e); free(a); free(b);
    return(js);
  }

