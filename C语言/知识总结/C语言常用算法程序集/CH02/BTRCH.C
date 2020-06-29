
  #include "stdlib.h"
  #include "math.h"
  #include "stdio.h"
  int btrch(t,tt,n,b)
  int n;
  double t[],tt[],b[];
  { int i,j,k;
    double a,s,*c,*r,*p;
    c=malloc(n*sizeof(double));
    r=malloc(n*sizeof(double));
    p=malloc(n*sizeof(double));
    if (fabs(t[0])+1.0==1.0)
      { free(c); free(r); free(p);
        printf("fail\n"); return(-1);
      }
    a=t[0]; c[0]=tt[1]/t[0]; r[0]=t[1]/t[0];
    for (k=0; k<=n-3; k++)
      { s=0.0;
        for (j=1; j<=k+1; j++)
          s=s+c[k+1-j]*tt[j];
        s=(s-tt[k+2])/a;
	for (i=0; i<=k; i++)
          p[i]=c[i]+s*r[k-i];
        c[k+1]=-s;
        s=0.0;
        for (j=1; j<=k+1; j++)
          s=s+r[k+1-j]*t[j];
        s=(s-t[k+2])/a;
        for (i=0; i<=k; i++)
          { r[i]=r[i]+s*c[k-i];
            c[k-i]=p[k-i];
          }
        r[k+1]=-s;
	a=0.0;
        for (j=1; j<=k+2; j++)
          a=a+t[j]*c[j-1];
        a=t[0]-a;
        if (fabs(a)+1.0==1.0)
          { free(c); free(r); free(p);
            printf("fail\n"); return(-1);
          }
      }
    b[0]=1.0/a;
    for (i=0; i<=n-2; i++)
      { k=i+1; j=(i+1)*n;
        b[k]=-r[i]/a; b[j]=-c[i]/a;
      }
    for (i=0; i<=n-1; i++)
    for (j=0; j<=n-2; j++)
      { k=(i+1)*n+j+1;
        b[k]=b[i*n+j]-c[i]*b[j+1];
        b[k]=b[k]+c[n-j-2]*b[n-i-1];
      }
    free(c); free(r); free(p);
    return(1);
  }

