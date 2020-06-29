
  #include "math.h"
  double enpqs(x,y,n,t)
  int n;
  double t,x[],y[];
  { int i,j,k,m,l;
    double z,h,b[8];
    z=0.0;
    if (n<1) return(z);
    if (n==1) { z=y[0]; return(z);}
    if (n<=8) { k=0; m=n;}
    else if (t<x[4]) { k=0; m=8;}
    else if (t>x[n-5]) { k=n-8; m=8;}
    else
      { k=1; j=n;
        while (j-k!=1)
          { i=(k+j)/2;
            if (t<x[i-1]) j=i;
            else k=i;
          }
        k=k-4; m=8;
      }
    b[0]=y[k];
    for (i=2;i<=m;i++)
      { h=y[i+k-1]; l=0; j=1;
        while ((l==0)&&(j<=i-1))
            { if (fabs(h-b[j-1])+1.0==1.0) l=1;
              else h=(x[i+k-1]-x[j+k-1])/(h-b[j-1]);
              j=j+1;
            }
        b[i-1]=h;
        if (l!=0) b[i-1]=1.0e+35;
      }
    z=b[m-1];
    for (i=m-1;i>=1;i--) z=b[i-1]+(t-x[i+k-1])/z;
    return(z);
  }

