
  #include "math.h"
  void scir3(row,col,a,b,color,xor)
  int row,col,a,b,color,xor;
  { int dx,dy,f,fx,fy,x,y,j,mx,my,
        lx,ly,r;
    extern int POINT();
    r=a;
    if (a<b) r=b;
    if ((a==0)&&(b==0)) return;
    lx=0; ly=0;
    j=8*r-1;
    dx=-1; dy=1;
    x=a; y=0;
    f=0; fx=2*r*dx+1; fy=1;
    mx=0; my=0;
    POINT(row-y,col+x,color,xor);
    while (j!=0)
      { if (f>=0)
          { lx=lx+a;
            if (lx>=r)
              { if (mx!=0) 
                  { POINT(row-y,col+x,color,xor); 
                    mx=0;
                  }
                x=x+dx; lx=lx-r;
                if (my!=0)
                  { my=0; 
                    POINT(row-y,col+x,color,xor);
                  }
                else mx=1;
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
              { if (my!=0)
                  { POINT(row-y,col+x,color,xor); 
                    my=0;
                  }
                y=y+dy; ly=ly-r;
                if (mx!=0)
                  { mx=0; 
                    POINT(row-y,col+x,color,xor);
                  }
                else my=1;
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
    if ((mx!=0)||(my!=0))
      POINT(row-y,col+x,color,xor);
    return;
  }

