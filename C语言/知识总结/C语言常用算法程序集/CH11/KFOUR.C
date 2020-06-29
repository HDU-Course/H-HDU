
  #include "math.h"
  void kfour(f,n,a,b)
  int n;
  double f[],a[],b[];
  { int i,j;
    double t,c,s,c1,s1,u1,u2,u0;
    t=6.283185306/(2.0*n+1.0);
    c=cos(t); s=sin(t);
    t=2.0/(2.0*n+1.0); c1=1.0; s1=0.0;
    for (i=0; i<=n; i++)
      { u1=0.0; u2=0.0;
        for (j=2*n; j>=1; j--)
          { u0=f[j]+2.0*c1*u1-u2;
            u2=u1; u1=u0;
          }
        a[i]=t*(f[0]+u1*c1-u2);
        b[i]=t*u1*s1;
        u0=c*c1-s*s1; s1=c*s1+s*c1; c1=u0;
      }
    return;
  }

