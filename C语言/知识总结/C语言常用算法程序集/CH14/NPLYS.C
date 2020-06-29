
  #include "math.h"
  #include "stdlib.h"
  void nplys(a,n,x,m,p)
  int n,m;
  double a[],x[],p[];
  { int i,j,mm,nn,ll,t,s,kk,k;
    double *b,y,z;
    b=malloc(2*n*sizeof(double));
    y=a[n-1];
    for (i=0; i<=n-1; i++) b[i]=a[i]/y;
    k=log(n-0.5)/log(2.0)+1;
    nn=1;
    for (i=0; i<=k-1; i++) nn=2*nn;
    for (i=n; i<nn-1; i++) b[i]=0.0;
    b[nn-1]=1.0;
    t=nn; s=1;
    for (i=1; i<=k-1; i++)
      { t=t/2; mm=-t;
        for (j=1; j<=s; j++)
          { mm=mm+t+t; b[mm-1]=b[mm-1]-1.0; 
            for (kk=2; kk<=t; kk++)
              b[mm-kk]=b[mm-kk]-b[mm-1]*b[mm+t-kk];
          }
        s=s+s;
      }
    for (kk=1; kk<=m; kk++)
      { for (i=0; i<=(nn-2)/2; i++)
           a[i]=x[kk-1]+b[2*i];
        mm=1; z=x[kk-1];
        for (i=1; i<=k-1; i++)
          { mm=mm+mm; ll=mm+mm; z=z*z;
            for (j=0; j<=nn-1; j=j+ll)
              a[j/2]=a[j/2]+a[(j+mm)/2]*(z+b[j+mm-1]);
          }
        z=z*z/x[kk-1];
        if (nn!=n) a[0]=a[0]-z;
        p[kk-1]=a[0]*y;
      }
    return;
  }

