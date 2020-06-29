
  void phkey(p,n,k,m)
  int n,k,m;
  HEAPSORT *p[];
  { int i,l;
    HEAPSORT *w;
    void phsift();
    if (k<0) k=0;
    if (m>n-1) m=n-1;
    l=m-k+1;
    for (i=l/2-1; i>=0; i--)
      phsift(p,k,i,l);
    for (i=l-1; i>=1; i--)
      { w=p[k]; p[k]=p[i+k]; p[i+k]=w;
        phsift(p,k,0,i);
      }
    return;
  }

  #include "string.h"
  static void phsift(p,k,i,l)
  int i,l,k;
  HEAPSORT *p[];
  { int m,n;
    char *t;
    HEAPSORT *w;
    t=(*p[i+k]).KEY; w=p[i+k]; n=2*(i+1)-1; m=i;
    while (n<=l-1)
      { if ((n<l-1)&&(strcmp((*p[n+k]).KEY,
			(*p[n+k+1]).KEY)<0)) n=n+1;
	if (strcmp(t,(*p[n+k]).KEY)<0)
          { p[m+k]=p[n+k];
            m=n; n=2*(m+1)-1;
          }
        else n=l;
      }
    p[m+k]=w;
    return;
  }

