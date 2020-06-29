  
  int agmiv(a,m,n,b,x,aa,eps,u,v,ka)
  int m,n,ka;
  double a[],b[],x[],aa[],u[],v[],eps;
  { int i,j;
    extern int bginv();
    i=bginv(a,m,n,aa,eps,u,v,ka);
    if (i<0) return(-1);
    for (i=0; i<=n-1; i++)
      { x[i]=0.0;
        for (j=0; j<=m-1; j++)
          x[i]=x[i]+aa[i*m+j]*b[j];
      }
    return(1);
  }

