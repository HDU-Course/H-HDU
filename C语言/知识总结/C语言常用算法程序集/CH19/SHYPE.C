
  #include "math.h"
  void shype(row,col,a,x1,y1,t,color,xor)
  int row,col,x1,y1,t,color,a,xor;
  { int n,dx,dy,x,y,x2,y2;
    double ct,st;
    double f,fx,fy,rx,ry,bb,aa;
    extern int POINT();
    st=(double)t*3.1415926/180.0;
    ct=cos(st); st=sin(st);
    n=abs(x1)+abs(y1)-a; n=n+n;
    dx=1; dy=1; f=0.0;
    if (x1>0) dx=-1;
    if (y1>0) dy=-1;
    x=x1; y=y1;
    x2=(double)x*ct-(double)y*st+2000.5;
    y2=(double)x*st+(double)y*ct+2000.5;
    x2=x2-2000; y2=y2-2000;
    POINT(row-y2,col+x2,color,xor);
    rx=1.0*a*a*y*y;
    ry=1.0*x1*x1-1.0*a*a;
    bb=rx/ry; aa=1.0*a*a;
    fx=bb*(2.0*x1*dx+1.0);
    fy=-aa*(2.0*y1*dy+1.0);
    rx=2.0*bb; ry=-2.0*aa;
    while (n>0)
      { n=n-1;
        if (f>=0.0)
          { x=x+dx;
            x2=(double)x*ct-(double)y*st+2000.5;
            y2=(double)x*st+(double)y*ct+2000.5;
            x2=x2-2000; y2=y2-2000;
            POINT(row-y2,col+x2,color,xor);
            if (fx>0.0) f=f-fx;
            else f=f+fx;
            fx=fx+rx;
            if (fx==0.0||(fx<0.0&&fx-rx>0.0)||
                         (fx>0.0&&fx-rx<0.0))
              { dy=-dy; fy=-fy+ry; f=-f;}
          }
        else
          { y=y+dy;
            x2=(double)x*ct-(double)y*st+2000.5;
            y2=(double)x*st+(double)y*ct+2000.5;
            x2=x2-2000; y2=y2-2000;
            POINT(row-y2,col+x2,color,xor);
            if (fy>0.0) f=f+fy;
            else f=f-fy;
            fy=fy+ry;
            if (fy==0.0||(fy<0.0&&fy-ry>0.0)||
                         (fy>0.0&&fy-ry<0.0))
              { dx=-dx; fx=-fx+rx; f=-f;}
          }
      }
    return;
  }

