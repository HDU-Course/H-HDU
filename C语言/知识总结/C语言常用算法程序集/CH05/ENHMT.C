
  double enhmt(x,y,dy,n,t)
  int n;
  double t,x[],y[],dy[];
  { int i,j;
    double z,p,q,s;
    z=0.0;
    for (i=1;i<=n;i++)
      { s=1.0;
        for (j=1;j<=n;j++)
          if (j!=i) s=s*(t-x[j-1])/(x[i-1]-x[j-1]);
        s=s*s;
        p=0.0;
        for (j=1;j<=n;j++)
          if (j!=i) p=p+1.0/(x[i-1]-x[j-1]);
        q=y[i-1]+(t-x[i-1])*(dy[i-1]-2.0*y[i-1]*p);
        z=z+q*s;
      }
    return(z);
  }

