
  #include "stdlib.h"
  int agmqr(a,m,n,b,q)
  int m,n;
  double a[],b[],q[];
  { int i,j;
    double d,*c;
    extern int bmaqr();
    c=malloc(n*sizeof(double));
    i=bmaqr(a,m,n,q);
    if (i==0) { free(c); return(0);}
    for (i=0; i<=n-1; i++)
      { d=0.0;
        for (j=0; j<=m-1; j++)
          d=d+q[j*m+i]*b[j];
        c[i]=d;
      }
    b[n-1]=c[n-1]/a[n*n-1];
    for (i=n-2; i>=0; i--)
      { d=0.0;
        for (j=i+1; j<=n-1; j++)
          d=d+a[i*n+j]*b[j];
        b[i]=(c[i]-d)/a[i*n+i];
      }
    free(c); return(1);
  }

