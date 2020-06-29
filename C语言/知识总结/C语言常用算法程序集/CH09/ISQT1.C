
  #include "math.h"
  void isqt1(x,y,n,a,dt)
  int n;
  double x[],y[],a[2],dt[6];
  { int i;
    double xx,yy,e,f,q,u,p,umax,umin,s;
    xx=0.0; yy=0.0;
    for (i=0; i<=n-1; i++)
      { xx=xx+x[i]/n; yy=yy+y[i]/n;}
    e=0.0; f=0.0;
    for (i=0; i<=n-1; i++)
      { q=x[i]-xx; e=e+q*q;
        f=f+q*(y[i]-yy);
      }
    a[1]=f/e; a[0]=yy-a[1]*xx;
    q=0.0; u=0.0; p=0.0;
    umax=0.0; umin=1.0e+30;
    for (i=0; i<=n-1; i++)
      { s=a[1]*x[i]+a[0];
        q=q+(y[i]-s)*(y[i]-s);
        p=p+(s-yy)*(s-yy);
        e=fabs(y[i]-s);
        if (e>umax) umax=e;
        if (e<umin) umin=e;
        u=u+e/n;
      }
    dt[1]=sqrt(q/n);
    dt[0]=q; dt[2]=p;
    dt[3]=umax; dt[4]=umin; dt[5]=u;
    return;
  }

