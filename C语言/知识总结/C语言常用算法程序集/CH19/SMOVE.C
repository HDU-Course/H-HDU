  
  void smove(row1,col1,row2,col2,row,col,xor)
  int row1,col1,row2,col2,row,col,xor;
  { int i,j,m,n,t,t1;
    long int k;
    extern int POINT();
    k=(long)(row-row1)*2000L+(long)(col-col1);
    if (k<0L)
      { m=row;
        for (i=row1; i<=row2; i++)
          { n=col;
            for (j=col1; j<=col2; j=j+1)
              { t=POINT(i,j,-1,0);
                t1=t;
                POINT(i,j,t1,1);
                POINT(m,n,t,xor);
                n=n+1;
              }
            m=m+1;
          }
      }
    else
      { m=row+(row2-row1);
        for (i=row2; i>=row1; i--)
          { n=col+(col2-col1);
            for (j=col2; j>=col1; j--)
              { t=POINT(i,j,-1,0);
                t1=t;
                POINT(i,j,t1,1);
                POINT(m,n,t,xor);
                n=n-1;
              }
            m=m-1;
          }
      }
    return;
  }

