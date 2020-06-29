
  int mrab1(a,b,r)
  int a,b,*r;
  { int k,l,m,i,p;
    k=b-a+1; l=2;
    while (l<k) l=l+l;
    m=4*l; k=*r; i=1;
    while (i<=1)
      { k=k+k+k+k+k;
	k=k%m; l=k/4+a;
        if (l<=b) { p=l; i=i+1;}
      }
    *r=k;
    return(p);
  }

