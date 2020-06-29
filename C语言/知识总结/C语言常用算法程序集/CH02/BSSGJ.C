
  #include "stdlib.h"
  #include "math.h"
  #include "stdio.h"
  int bssgj(a,n)
  int n;
  double a[];
  { int i,j,k,m;
    double w,g,*b;
    b=malloc(n*sizeof(double));
    for (k=0; k<=n-1; k++)
      { w=a[0];
        if (fabs(w)+1.0==1.0)
          { free(b); printf("fail\n"); return(-2);}
        m=n-k-1;
        for (i=1; i<=n-1; i++)
          { g=a[i*n]; b[i]=g/w;
            if (i<=m) b[i]=-b[i];
            for (j=1; j<=i; j++)
              a[(i-1)*n+j-1]=a[i*n+j]+g*b[j];
          }
        a[n*n-1]=1.0/w;
        for (i=1; i<=n-1; i++)
          a[(n-1)*n+i-1]=b[i];
      }
    for (i=0; i<=n-2; i++)
    for (j=i+1; j<=n-1; j++)
      a[i*n+j]=a[j*n+i];
    free(b);
    return(2);
  }

