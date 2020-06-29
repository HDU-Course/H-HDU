
  #include "math.h"
  void npmul(p,m,q,n,s,k)
  int m,n,k;
  double p[],q[],s[];
  { int i,j;
    for (i=0; i<=k-1; i++) s[i]=0.0;
    for (i=0; i<=m-1; i++)
    for (j=0; j<=n-1; j++)
      s[i+j]=s[i+j]+p[i]*q[j];
    return;
  }

