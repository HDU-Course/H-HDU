
  double eehmt(x0,h,n,y,dy,t)
  int n;
  double x0,h,t,y[],dy[];
  { int i,j;
    double z,s,p,q;
    z=0.0;
    for (i=1;i<=n;i++)
      { s=1.0; q=x0+(i-1)*h;
        for (j=1;j<=n;j++)
          { p=x0+(j-1)*h;
            if (j!=i) s=s*(t-p)/(q-p);
          }
        s=s*s;
        p=0.0;
        for (j=1;j<=n;j++)
          if (j!=i) p=p+1.0/(q-(x0+(j-1)*h));
        q=y[i-1]+(t-q)*(dy[i-1]-2.0*y[i-1]*p);
        z=z+q*s;
      }
    return(z);
  }


