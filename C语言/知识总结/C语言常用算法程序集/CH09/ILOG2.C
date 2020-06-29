
  #include "math.h"
  void ilog2(n,x,y,a)
  int n;
  double x[],y[],a[7];
  { int i;
    double xx,yy,dx,dxy;
    xx=0.0; yy=0.0;
    for (i=0; i<=n-1; i++)
      { xx=xx+log(x[i])/n; 
        yy=yy+log(y[i])/n;
      }
    dx=0.0; dxy=0.0;
    for (i=0; i<=n-1; i++)
      { a[2]=log(x[i])-xx; dx=dx+a[2]*a[2];
        dxy=dxy+a[2]*(log(y[i])-yy);
      }
    a[1]=dxy/dx; a[0]=yy-a[1]*xx;
    a[0]=exp(a[0]);
    a[2]=0.0; a[6]=0.0; a[4]=0.0; a[5]=1.0e+30;
    for (i=0; i<=n-1; i++)
      { a[3]=a[1]*log(x[i]); a[3]=a[0]*exp(a[3]);
        a[2]=a[2]+(y[i]-a[3])*(y[i]-a[3]);
        dx=fabs(y[i]-a[3]);
        if (dx>a[4]) a[4]=dx;
        if (dx<a[5]) a[5]=dx;
        a[6]=a[6]+dx/n;
      }
    a[3]=sqrt(a[2]/n);
    return;
  }

