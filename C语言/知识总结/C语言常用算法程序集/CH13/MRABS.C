
  void mrabs(a,b,r,p,n)
  int a,b,*r,n,p[];
  { int k,l,m,i;
    k=b-a+1; l=2;
    while (l<k) l=l+l;
    m=4*l; k=*r; i=0;
    while (i<=n-1)
      { k=k+k+k+k+k;
	k=k%m; l=k/4+a;
        if (l<=b) { p[i]=l; i=i+1;}
      }
    *r=k;
    return;
  }

