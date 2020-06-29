
  #include "math.h"
  void npdiv(p,m,q,n,s,k,r,l)
  int m,n,k,l;
  double p[],q[],s[],r[];
  { int i,j,mm,ll;
    for (i=0; i<=k-1; i++) s[i]=0.0;
    if (q[n-1]+1.0==1.0) return;
    ll=m-1;
    for (i=k; i>=1; i--)
      { s[i-1]=p[ll]/q[n-1];
        mm=ll;
        for (j=1; j<=n-1; j++)
          { p[mm-1]=p[mm-1]-s[i-1]*q[n-j-1];
            mm=mm-1;
          }
        ll=ll-1;
      }
    for (i=0; i<=l-1; i++) r[i]=p[i];
    return;
  }

