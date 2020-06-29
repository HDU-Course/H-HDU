
  #include "math.h"
  double eelg3(x0,h,n,y,t)
  int n;
  double x0,h,t,y[];
  { int i,j,k,m;
    double z,s,xi,xj;
    z=0.0;
    if (n<1) return(z);
    if (n==1) { z=y[0]; return(z);}
    if (n==2)
      { z=(y[1]*(t-x0)-y[0]*(t-x0-h))/h;
        return(z);
      }
    if (t<=x0+h) { k=0; m=2;}
    else if (t>=x0+(n-3)*h) { k=n-3; m=n-1;}
    else
      { i=(int)((t-x0)/h)+1;
        if (fabs(t-x0-i*h)>=fabs(t-x0-(i-1)*h))
          { k=i-2; m=i;}
        else {k=i-1; m=i+1;}
      }
    z=0.0;
    for (i=k;i<=m;i++)
      { s=1.0; xi=x0+i*h;
        for (j=k;j<=m;j++)
          if (j!=i)
            { xj=x0+j*h; s=s*(t-xj)/(xi-xj);}
        z=z+s*y[i];
      }
    return(z);
  }

