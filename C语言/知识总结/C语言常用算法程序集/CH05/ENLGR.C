
  double enlgr(x,y,n,t)
  int n;
  double t,x[],y[];
  { int i,j,k,m;
    double z,s;
    z=0.0;
    if (n<1) return(z);
    if (n==1) { z=y[0];return(z);}
    if (n==2)
      { z=(y[0]*(t-x[1])-y[1]*(t-x[0]))/(x[0]-x[1]);
        return(z);
      }
    i=0;
    while ((x[i]<t)&&(i<n)) i=i+1;
    k=i-4;
    if (k<0) k=0;
    m=i+3;
    if (m>n-1) m=n-1;
    for (i=k;i<=m;i++)
      { s=1.0;
        for (j=k;j<=m;j++)
          if (j!=i) s=s*(t-x[j])/(x[i]-x[j]);
        z=z+s*y[i];
      }
    return(z);
  }

