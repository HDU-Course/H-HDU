
  void pibub(p,n)
  int p[],n;
  { int m,k,j,i,d;
    k=0; m=n-1;
    while (k<m)
      { j=m-1; m=0;
        for (i=k; i<=j; i++)
          if (p[i]>p[i+1])
            { d=p[i]; p[i]=p[i+1]; p[i+1]=d; m=i;}
        j=k+1; k=0;
        for (i=m; i>=j; i--)
          if (p[i-1]>p[i])
            { d=p[i]; p[i]=p[i-1]; p[i-1]=d; k=i;}
      }
    return;
  }

