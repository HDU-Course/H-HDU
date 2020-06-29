
  int qbkey(p,n,a,b,m)
  int n,*m;
  BISERCH *p[];
  SERCHTYPE a,b;
  { int i,j,k;
    i=1; j=n;
    while (i<=j)
      { k=(i+j)/2;
        if (((*p[k-1]).KEY>=a)&&((*p[k-1]).KEY<=b))
          { i=k-1; j=0;
            while ((i>=0)&&((*p[i]).KEY>=a)) 
                { i=i-1; j=j+1;}
            i=i+1;
            while ((k<=n-1)&&((*p[k]).KEY<=b)) 
                { k=k+1; j=j+1;}
            *m=j; return(i);
          }
        if ((*p[k-1]).KEY>b) j=k-1;
        else i=k+1;
      }
    while ((i>=0)&&(b<(*p[i]).KEY)) i=i-1;
    i=i+1; *m=0;
    return(i);
  }

