
  #include "string.h"
  void phbub(p,n,k,m)
  char *p[];
  int k,m,n;
  { int j,i;
    char *d;
    if (k<0) k=0;
    if (m>n-1) m=n-1;
    while (k<m)
      { j=m-1; m=0;
        for (i=k; i<=j; i++)
          if (strcmp(p[i],p[i+1])>0)
	    { d=p[i]; p[i]=p[i+1]; p[i+1]=d; m=i;}
        j=k+1; k=0;
        for (i=m; i>=j; i--)
          if (strcmp(p[i-1],p[i])>0)
            { d=p[i]; p[i]=p[i-1]; p[i-1]=d; k=i;}
      }
    return;
  }

