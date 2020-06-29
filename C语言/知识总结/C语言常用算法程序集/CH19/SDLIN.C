
  void sdlin(row1,col1,row2,col2,rl,il,color,xor)
  int row1,col1,row2,col2,rl,il,color,xor;
  { int dx,dy,dm,dn,m,n,k,u,v,l,sum,contr,conti;
    extern int POINT();
    dx=row2-row1; dy=col2-col1;
    if (dx==0)
      { u=col1; v=col2;
        if (dy<0) { u=col2; v=col1;}
        contr=rl; conti=0;
        for (l=u; l<=v-1; l++)
          { if (contr!=0)
              { POINT(row2,l,color,xor);
                contr=contr-1;
                if (contr==0) conti=2*il+1;
              }
            else
              { if (conti==(il+1))
		  POINT(row2,l,color,xor);
                conti=conti-1;
                if (conti==0) contr=rl;
              }
          }
        POINT(row2,v,color,xor);
        return;
      }
    if (dy==0)
      { u=row1; v=row2;
        if (dx<0) {u=row2; v=row1;}
        contr=rl; conti=0;
        for (l=u; l<=v-1; l++)
          { if (contr!=0)
              { POINT(l,col2,color,xor);
                contr=contr-1;
                if (contr==0) conti=2*il+1;
              }
            else
              { if (conti==(il+1))
                  POINT(l,col2,color,xor);
                conti=conti-1;
                if (conti==0) contr=rl;
              }
          }
        POINT(v,col2,color,xor);
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
    rl=((long)rl*(long)m)/(long)(sqrt((long)m
            *(long)m+(long)n*(long)n));
    il=((long)il*(long)m)/(long)(sqrt((long)m
            *(long)m+(long)n*(long)n));
    l=0; sum=m; POINT(row1,col1,color,xor);
    contr=rl-1; conti=0;
    while (sum!=1)
      { sum=sum-1; l=l+n; u=u+dm;
        if (l>=m) { v=v+dn; l=l-m;}
        if (contr!=0)
          { if (k==1) POINT(u,v,color,xor);
            else POINT(v,u,color,xor);
            contr=contr-1;
            if (contr==0) conti=2*il+1;
          }
        else
          { if (conti==(il+1))
              { if (k==1) POINT(u,v,color,xor);
                else POINT(v,u,color,xor);
              }
            conti=conti-1;
            if (conti==0) contr=rl;
          }
      }
    POINT(row2,col2,color,xor);
    return;
  }

