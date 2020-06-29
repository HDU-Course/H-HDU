
  #include "math.h"
  #include "stdlib.h"
  void isqt2(x,y,m,n,a,dt,v)
  int m,n;
  double x[],y[],a[],dt[],v[];
  { int i,j,k,l,mm;
    double q,e,u,p,yy,s,r,pp,*b;
    extern int achol();
    b=malloc((m+1)*(m+1)*sizeof(double));
    mm=m+1;
    b[mm*mm-1]=n;
    for (j=0; j<=m-1; j++)
      { p=0.0;
        for (i=0; i<=n-1; i++)
          p=p+x[j*n+i];
        b[m*mm+j]=p;
        b[j*mm+m]=p;
      }
    for (i=0; i<=m-1; i++)
      for (j=i; j<=m-1; j++)
        { p=0.0;
          for (k=0; k<=n-1; k++)
            p=p+x[i*n+k]*x[j*n+k];
          b[j*mm+i]=p;
          b[i*mm+j]=p;
        }
    a[m]=0.0;
    for (i=0; i<=n-1; i++)
      a[m]=a[m]+y[i];
    for (i=0; i<=m-1; i++)
      { a[i]=0.0;
        for (j=0; j<=n-1; j++)
          a[i]=a[i]+x[i*n+j]*y[j];
      }
    achol(b,mm,1,a);
    yy=0.0;
    for (i=0; i<=n-1; i++)
      yy=yy+y[i]/n;
    q=0.0; e=0.0; u=0.0;
    for (i=0; i<=n-1; i++)
      { p=a[m];
        for (j=0; j<=m-1; j++)
          p=p+a[j]*x[j*n+i];
        q=q+(y[i]-p)*(y[i]-p);
        e=e+(y[i]-yy)*(y[i]-yy);
        u=u+(yy-p)*(yy-p);
      }
    s=sqrt(q/n);
    r=sqrt(1.0-q/e);
    for (j=0; j<=m-1; j++)
      { p=0.0;
        for (i=0; i<=n-1; i++)
          { pp=a[m];
            for (k=0; k<=m-1; k++)
              if (k!=j) pp=pp+a[k]*x[k*n+i];
            p=p+(y[i]-pp)*(y[i]-pp);
          }
        v[j]=sqrt(1.0-q/p);
      }
    dt[0]=q; dt[1]=s; dt[2]=r; dt[3]=u;
    free(b); return;
  }

