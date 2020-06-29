
  #include "math.h"
  #include "stdlib.h"
  #include "stdio.h"
  void agrad(a,n,b,eps,x)
  int n;
  double a[],b[],x[],eps;
  { int i,k;
    double *p,*r,*s,*q,alpha,beta,d,e;
    extern void brmul();
    p=malloc(n*sizeof(double));
    r=malloc(n*sizeof(double));
    s=malloc(n*sizeof(double));
    q=malloc(n*sizeof(double));
    for (i=0; i<=n-1; i++)
      { x[i]=0.0; p[i]=b[i]; r[i]=b[i]; }
    i=0;
    while (i<=n-1)
      { brmul(a,p,n,n,1,s);
        d=0.0; e=0.0;
        for (k=0; k<=n-1; k++)
           { d=d+p[k]*b[k]; e=e+p[k]*s[k]; }
        alpha=d/e;
        for (k=0; k<=n-1; k++)
           x[k]=x[k]+alpha*p[k];
        brmul(a,x,n,n,1,q);
        d=0.0;
        for (k=0; k<=n-1; k++)
          { r[k]=b[k]-q[k]; d=d+r[k]*s[k]; }
        beta=d/e; d=0.0;
        for (k=0; k<=n-1; k++) d=d+r[k]*r[k];
        d=sqrt(d);
        if (d<eps) 
          { free(p); free(r); free(s); free(q);return;}
        for (k=0; k<=n-1; k++)
           p[k]=r[k]-beta*p[k];
        i=i+1;
      }
    free(p); free(r); free(s); free(q);
    return;
  }

