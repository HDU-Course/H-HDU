
  #include "math.h"
  double fromb(a,b,eps)
  double a,b,eps;
  { extern double frombf();
    int m,n,i,k;
    double y[10],h,ep,p,x,s,q;
    h=b-a;
    y[0]=h*(frombf(a)+frombf(b))/2.0;
    m=1; n=1; ep=eps+1.0;
    while ((ep>=eps)&&(m<=9))
      { p=0.0;
        for (i=0;i<=n-1;i++)
          { x=a+(i+0.5)*h;
            p=p+frombf(x);
          }
        p=(y[0]+h*p)/2.0;
        s=1.0;
        for (k=1;k<=m;k++)
          { s=4.0*s;
            q=(s*p-y[k-1])/(s-1.0);
            y[k-1]=p; p=q;
          }
        ep=fabs(q-y[m-1]);
        m=m+1; y[m-1]=q; n=n+n; h=h/2.0;
      }
    return(q);
  }

