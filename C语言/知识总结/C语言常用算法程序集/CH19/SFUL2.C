
  #include "math.h"
  void sful2(row,col,a,b,color,xor)
  int row,col,a,b,color,xor;
  { int dx,dy,f,fx,fy,x,y,r,j,lx,ly;
    extern int POINT();
    extern void sline();
    if ((a==0)&&(b==0)) return;
    r=a;
    if (a<b) r=b;
    dx=-1; dy=1;
    lx=0; ly=0;
    f=0; fx=-2*r+1; fy=1;
    x=a; y=0; j=2*r-1;
    sline(row-y,col+x,row+y,col+x,color,xor);
    sline(row-y,col-x,row+y,col-x,color,xor);
    while (j!=0)
      { if (f>=0)
          { lx=lx+a;
            if (lx>=r)
              { x=x+dx; lx=lx-r;
                sline(row-y,col+x,row+y,col+x,color,xor);
                sline(row-y,col-x,row+y,col-x,color,xor);
              }
            if (fx>0) f=f-fx;
            else f=f+fx;
            fx=fx+2;
            if ((fx==0)||((fx<0)&&(fx-2>0))||
                         ((fx>0)&&(fx-2<0)))
              { dy=-dy; fy=-fy+2; f=-f;}
          }
        else
          { ly=ly+b;
            if (ly>=r)
              { y=y+dy; ly=ly-r;
                POINT(row-y,col+x,color,xor);
                POINT(row+y,col+x,color,xor);
                POINT(row-y,col-x,color,xor);
                POINT(row+y,col-x,color,xor);
              }
            if (fy>0) f=f+fy;
            else f=f-fy;
            fy=fy+2;
            if ((fy==0)||((fy<0)&&(fy-2>0))||
                         ((fy>0)&&(fy-2<0)))
              { dx=-dx; fx=-fx+2; f=-f;}
          }
        j=j-1;
      }
    x=0; y=b;
    sline(row-y,col+x,row+y,col+x,color,xor);
    return;
  }

