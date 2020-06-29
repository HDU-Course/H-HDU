
  #include "math.h"
  double eepqs(x0,h,n,y,t)
  int n;
  double x0,h,t,y[];
  { int i,j,k,m,l;
    double z,hh,xi,xj,b[8];
    z=0.0;
    if (n<1) return(z);
    if (n==1) { z=y[0]; return(z);}
    if (n<=8) { k=0; m=n;}
    else if (t<(x0+4.0*h)) { k=0; m=8;}
    else if (t>(x0+(n-5)*h)) { k=n-8; m=8;}
    else { k=(int)((t-x0)/h)-3; m=8;}
    b[0]=y[k];
    for (i=2;i<=m;i++)
      { hh=y[i+k-1]; l=0; j=1;
        while ((l==0)&&(j<=i-1))
            { if (fabs(hh-b[j-1])+1.0==1.0) l=1;
              else
                { xi=x0+(i+k-1)*h;
                  xj=x0+(j+k-1)*h;
                  hh=(xi-xj)/(hh-b[j-1]);
                }
              j=j+1;
            }
        b[i-1]=hh;
        if (l!=0) b[i-1]=1.0e+35;
      }
    z=b[m-1];
    for (i=m-1;i>=1;i--)
      z=b[i-1]+(t-(x0+(i+k-1)*h))/z;
    return(z);
  }

