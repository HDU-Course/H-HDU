
  #include "string.h"
  int qhbsh(p,n,a,b,m)
  int n,*m;
  char a[],b[],*p[];
  { int i,j,k;
    i=1; j=n;
    while (i<=j)
      { k=(i+j)/2;
        if ((strcmp(p[k-1],a)>=0)&&(strcmp(p[k-1],b)<=0))
          { i=k-1; j=0;
            while ((i>=0)&&(strcmp(p[i],a)>=0)) 
                { i=i-1; j=j+1;}
            i=i+1;
            while ((k<=n-1)&&(strcmp(p[k],b)<=0)) 
                { k=k+1; j=j+1;}
            *m=j; return(i);
          }
        if (strcmp(p[k-1],b)>0) j=k-1;
        else i=k+1;
      }
    while ((i>=0)&&(strcmp(b,p[i])<0)) i=i-1;
    i=i+1; *m=0;
    return(i);
  }

