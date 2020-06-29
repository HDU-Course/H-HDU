
  #include "math.h"
  void sccpy(row1,col1,a,b,row,col,xor)
  int row1,col1,a,b,row,col,xor;
  { int i,j,m,n,t,l;
    double w;
    long int k;
    extern int POINT();
    k=(long)(row-row1)*2000L+(long)(col-col1);
    if (k<0L)
      { m=row-b;
        for (i=b; i>=-b; i--)
          { w=(double)i/(double)b;
            w=sqrt(1.0-w*w);
            w=(double)a*w;
            l=(int)w; n=col-l;
            for (j=-l; j<=l; j=j+1)
              { t=POINT(row1-i,col1+j,-1,0);
                POINT(m,n,t,xor);
                n=n+1;
              }
            m=m+1;
          }
      }
    else
      { m=row+b;
        for (i=-b; i<=b; i++)
          { w=(double)i/(double)b;
            w=sqrt(1.0-w*w);
            w=(double)a*w;
            l=(int)w; n=col+l;
            for (j=l; j>=-l; j--)
              { t=POINT(row1-i,col1+j,-1,0);
                POINT(m,n,t,xor);
                n=n-1;
              }
            m=m-1;
          }
      }
    return;
  }

