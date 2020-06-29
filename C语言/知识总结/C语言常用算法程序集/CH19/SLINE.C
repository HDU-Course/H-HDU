
  void sline(row1,col1,row2,col2,color,xor)
  int row1,col1,row2,col2,color,xor;
  { int dx,dy,dm,dn,m,n,k,u,v,l,sum;
    extern int POINT();
    dx=row2-row1; dy=col2-col1;
    if (dx==0)
      { u=col1; v=col2;
        if (dy<0) { u=col2; v=col1;}
        for (l=u; l<=v; l++)
          POINT(row2,l,color,xor);
        return;
      }
    if (dy==0)
      { u=row1; v=row2;
        if (dx<0) {u=row2; v=row1;}
        for (l=u; l<=v; l++)
          POINT(l,col2,color,xor);
        return;
      } 
    dm=1; dn=1;
    if (dx<0) { dx=-dx; dm=-1;}
    if (dy<0) { dy=-dy; dn=-1;}
    m=dx; n=dy; k=1; u=row1; v=col1;
    if (dx<dy)
      { m=dy; n=dx; 
        k=dm; dm=dn; dn=k; k=0;
	u=col1; v=row1;
      }
    l=0; sum=m; POINT(row1,col1,color,xor);
    while (sum!=0)
      { sum=sum-1; l=l+n; u=u+dm;
        if (l>=m) { v=v+dn; l=l-m;}
        if (k==1) POINT(u,v,color,xor);
        else POINT(v,u,color,xor);
      }
    return;
  }

