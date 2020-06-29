
  #include "string.h"
  void phshl(p,n,k,m)
  int n,k,m;
  char *p[];
  { int kk,j,i;
    char *t;
    n=n+0;
    kk=(m-k)/2;
    while (kk>0)
      { for (j=k+kk; j<=m; j++)
          { t=p[j]; i=j-kk;
            while ((i>=0)&&(strcmp(p[i],t)>0))
              { p[i+kk]=p[i]; i=i-kk;}
            p[i+kk]=t;
          }
        kk=kk/2;
      }
    return;
  }

