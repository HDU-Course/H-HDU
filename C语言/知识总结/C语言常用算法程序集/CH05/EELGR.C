
  double eelgr(x0,h,n,y,t)
  int n;
  double x0,h,t,y[];
  { int i,j,k,m;
    double z,s,xi,xj;
    float p,q;
    z=0.0;
    if (n<1) return(z);
    if (n==1) { z=y[0]; return(z);}
    if (n==2)
      { z=(y[1]*(t-x0)-y[0]*(t-x0-h))/h;
        return(z);
      }
    if (t>x0)
      { p=(t-x0)/h; i=(int)p; q=(float)i;
        if (p>q) i=i+1;
      }
    else i=0;
    k=i-4;
    if (k<0) k=0;
    m=i+3;
    if (m>n-1) m=n-1;
    for (i=k;i<=m;i++)
      { s=1.0; xi=x0+i*h;
        for (j=k; j<=m; j++)
          if (j!=i)
            { xj=x0+j*h;
              s=s*(t-xj)/(xi-xj);
            }
        z=z+s*y[i];
      }
    return(z);
  }

