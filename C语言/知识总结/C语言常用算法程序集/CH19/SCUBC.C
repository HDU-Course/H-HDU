
  #include "math.h"
  void scubc(row,col,b,c,d,xt,t,color,xor)
  int row,col,color,xt,t,xor;
  double b,c,d;
  { int n,dx,dy,x,y,x2,y2;
    double ct,st;
    double f,fx,rx,rx1;
    extern int POINT();
    st=(double)t*3.1415926/180.0;
    ct=cos(st); st=sin(st);
    n=abs(xt);
    dx=1; dy=1;
    if (xt<0) dx=-1;
    fx=b+d+c*(double)dx;
    if (fx<0.0) dy=-1;
    dy=dx*dy;
    f=0.0;
    rx=2.0*c*(double)dx; rx1=6.0*d;
    x=0; y=0;
    POINT(row,col,color,xor);
    while (n>0)
      { if (f>=0.0)
          { x=x+dx; n=n-1;
            x2=(double)x*ct-(double)y*st+2000.5;
            y2=(double)x*st+(double)y*ct+2000.5;
            x2=x2-2000; y2=y2-2000;
            POINT(row-y2,col+x2,color,xor);
            if (fx>0.0) f=f-fx;
            else f=f+fx;
            rx=rx+rx1; fx=fx+rx;
            if (fx==0.0||(fx<0.0&&fx-rx>0.0)||
                         (fx>0.0&&fx-rx<0.0))
              { dy=-dy; f=-f;}
          }
        else
          { y=y+dy;
            x2=(double)x*ct-(double)y*st+2000.5;
            y2=(double)x*st+(double)y*ct+2000.5;
            x2=x2-2000; y2=y2-2000;
            POINT(row-y2,col+x2,color,xor);
	    f=f+1.0;
          }
      }
    return;
  }

