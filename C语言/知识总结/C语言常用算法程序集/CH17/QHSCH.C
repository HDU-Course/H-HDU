
  #include "string.h"
  int qhsch(p,k,m,a,b)
  STRU p[];
  char a[],b[];
  int k,m;
  { int i;
    i=k;
    while ((i<=m)&&((strcmp(p[i].KEY,a)<0)||
           (strcmp(p[i].KEY,b)>0))) i=i+1;
    if (i>m) return(-1);
    return(i);
  }

