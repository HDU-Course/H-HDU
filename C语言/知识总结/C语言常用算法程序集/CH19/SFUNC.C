
  #include "math.h"
  void sfunc(row,col,x0,xn,t,color,xor)
  int row,col,x0,xn,t,color,xor;
  { int i,x1,x2,y1,y2;
    extern void sline();
    extern int POINT();
    extern double fun();
    double x,y,st,ct;
    st=(double)t*3.1415926/180.0;
    ct=cos(st); st=sin(st);
    x=(double)x0; y=fun(x);
    x1=(int)(x*ct-y*st);
    y1=(int)(x*st+y*ct);
    for (i=x0+1; i<=xn; i++)
      { x=(double)i; y=fun(x);
        x2=(int)(x*ct-y*st);
        y2=(int)(x*st+y*ct);
        sline(row-y1,col+x1,row-y2,
                     col+x2,color,xor);
        POINT(row-y2,col+x2,color,xor);
        x1=x2; y1=y2;
      }
    POINT(row-y1,col+x1,color,xor);
    return;
  }

