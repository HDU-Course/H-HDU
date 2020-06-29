
  #include "math.h"
  void ncply(ar,ai,n,x,y,u,v)
  int n;
  double x,y,ar[],ai[],*u,*v;
  { int i;
    double p,q,s,t;
    extern void ocmul();
    s=ar[n-1]; t=ai[n-1];
    for (i=n-2; i>=0; i--)
      { ocmul(s,t,x,y,&p,&q);
        s=p+ar[i]; t=q+ai[i];
      }
    *u=s; *v=t;
    return;
  }

