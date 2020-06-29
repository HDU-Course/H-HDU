
  void pcqck(p,n)
  int n;
  char p[];
  { int m,i0,*i;
    char *s;
    void csplit();
    extern void pcbub();
    i=&i0;
    if (n>10)
      { csplit(p,n,i);
        m=i0;
	pcqck(p,m);
	s=p+(i0+1);
        m=n-(i0+1);
	pcqck(s,m);
      }
    else pcbub(p,n);
    return;
  }

  static void csplit(p,n,m)
  int n,*m;
  char p[];
  { int i,j,k,l;
    char t;
    i=0; j=n-1;
    k=(i+j)/2;
    if ((p[i]>=p[j])&&(p[j]>=p[k])) l=j;
    else if ((p[i]>=p[k])&&(p[k]>=p[j])) l=k;
    else l=i;
    t=p[l]; p[l]=p[i];
    while (i!=j)
      { while ((i<j)&&(p[j]>=t)) j=j-1;
        if (i<j)
          { p[i]=p[j]; i=i+1;
            while ((i<j)&&(p[i]<=t)) i=i+1;
            if (i<j)
              { p[j]=p[i]; j=j-1;}
          }
      }
    p[i]=t; *m=i;
    return;
  }

