
  void prqck(p,n)
  int n;
  double p[];
  { int m,i0,*i;
    double *s;
    void rsplit();
    extern void prbub();
    i=&i0;
    if (n>10)
      { rsplit(p,n,i);
        m=i0;
        prqck(p,m);
	s=p+(i0+1);
        m=n-(i0+1);
        prqck(s,m);
      }
    else prbub(p,n);
    return;
  }

  static void rsplit(p,n,m)
  int n,*m;
  double p[];
  { int i,j,k,l;
    double t;
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