
  void phqck(p,n,k,m)
  int n,k,m;
  char *p[];
  { int i0,*i;
    void hsplit();
    extern void phbub();
    i=&i0;
    if (k<0) k=0;
    if (m>n-1) m=n-1;
    if (m-k>10)
      { hsplit(p,k,m,i);
	phqck(p,n,k,i0-1);
	phqck(p,n,i0+1,m);
      }
    else phbub(p,n,k,m);
    return;
  }

  #include "string.h"
  static void hsplit(p,k,m,i)
  int k,m,*i;
  char *p[];
  { int ii,kk,j,l;
    char *t;
    ii=k; j=m;
    kk=(ii+j)/2;
    if ((strcmp(p[ii],p[j])>=0)&&(strcmp(p[j],p[kk])>=0))
        l=j;
    else if ((strcmp(p[ii],p[kk])>=0)&&(strcmp(p[kk],p[j])
          >=0)) l=kk;
    else l=ii;
    t=p[l]; p[l]=p[ii];
    while (ii!=j)
      { while ((ii<j)&&(strcmp(p[j],t)>=0)) j=j-1;
        if (ii<j)
          { p[ii]=p[j]; ii=ii+1;
            while ((ii<j)&&(strcmp(p[ii],t)<=0)) ii=ii+1;
            if (ii<j)
              { p[j]=p[ii]; j=j-1;}
          }
      }
    p[ii]=t; *i=ii;
    return;
  }

