
  void phhap(p,n,k,m)
  int n,k,m;
  char *p[];
  { int i,l;
    char *t;
    void hsift();
    if (k<0) k=0;
    if (m>n-1) m=n-1;
    l=m-k+1;
    for (i=l/2-1; i>=0; i--)
      hsift(p,k,i,l);
    for (i=l-1; i>=1; i--)
      { t=p[k]; p[k]=p[i+k]; p[i+k]=t;
        hsift(p,k,0,i);
      }
    return;
  }

  #include "string.h"
  static void hsift(p,k,i,l)
  int i,l,k;
  char *p[];
  { int m,n;
    char *t;
    t=p[i+k]; m=i; n=2*(i+1)-1;
    while (n<=l-1)
      { if ((n<l-1)&&(strcmp(p[n+k],p[n+1+k])<0)) n=n+1;
        if (strcmp(t,p[n+k])<0)
          { p[m+k]=p[n+k]; m=n; n=2*(m+1)-1;}
        else n=l;
      }
    p[m+k]=t;
    return;
  }

