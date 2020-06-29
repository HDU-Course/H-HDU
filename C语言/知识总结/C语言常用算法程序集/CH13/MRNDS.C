
  void mrnds(r,p,n)
  double *r,p[];
  int n;
  { int i,m;
    double s,u,v;
    s=65536.0; u=2053.0; v=13849.0;
    for (i=0; i<=n-1; i++)
      { *r=u*(*r)+v; m=(int)(*r/s);
        *r=*r-m*s; p[i]=*r/s;
      }
    return;
  }

