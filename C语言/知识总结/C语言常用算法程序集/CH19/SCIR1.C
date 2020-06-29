
  #include "math.h"
  void scir1(row,col,a,b,t1,t2,color,xor)
  int row,col,a,b,t1,t2,color,xor;
  { int dx,dy,f,fx,fy,x,y,j,mx,my,
        x1,y1,lx,ly,r,j1;
    double t;
    extern int POINT();
    t=((double)t1/180.0)*3.1415926;
    r=a;
    if (a<b) r=b;
    x1=(double)r*cos(t)+0.5;
    y1=(double)r*sin(t)+0.5;
    t=(double)t2-(double)t1;
    while (fabs(t)>360.0)
      { if(t>0.0) t=t-360.0;
        else t=t+360.0;
      }
    if ((x1==0)&&(y1==0)) return;
    if (fabs(t)+1.0==1.0) t=360.0;
    if (t>0.0)
      { if (y1==0)
          { if (x1>0) dx=-1;
            else dx=1;
          }
        else
          { if (y1>0) dx=-1;
            else dx=1;
          }
        if (x1==0)
          { if (y1>0) dy=-1;
            else dy=1;
          }
        else
          { if (x1>0) dy=1;
            else dy=-1;
          }
      }
    else
      { if (y1==0)
          { if (x1>0) dx=-1;
            else dx=1;
          }
        else
          { if (y1>0) dx=1;
            else dx=-1;
          }
        if (x1==0)
          { if (y1>0) dy=-1;
            else dy=1;
          }
        else
          { if (x1>0) dy=-1;
            else dy=1;
          }
      }
    lx=0; ly=0;
    j1=0; t2=t1;
    while (t2>=90) { j1=j1+2*r; t2=t2-90;}
    x=r*cos(t2*3.1415926/180.0);
    y=r*sin(t2*3.1415926/180.0);
    j1=j1+y+(r-x);
    j=0;
    t2=t; t=t1+t;
    if (t2>0.0)
      { while (t>=90.0)
          { j=j+2*r; t=t-90.0;}
        x=r*cos(t*3.1415926/180.0)+0.5;
        y=r*sin(t*3.1415926/180.0)+0.5;
        j=j+y+(r-x); j=j-j1;
      }
    else
      { if (t>=0.0) t2=1;
        else { t2=0; t=-t;}
        while (t>=90.0)
          { j=j+2*r; t=t-90.0;}
        x=r*cos(t*3.1415926/180.0)+0.5;
        y=r*sin(t*3.1415926/180.0)+0.5;
        j=j+y+(r-x);
        if (t2==1) j=j1-j;
        else j=j+j1;
      }
    j=j-1;
    f=0; fx=2*x1*dx+1; fy=2*y1*dy+1;
    mx=0; my=0;
    t=((double)t1/180.0)*3.1415926;
    x=(int)((double)a*cos(t)+0.5);
    y=(int)((double)b*sin(t)+0.5);
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
    if ((mx==0)&&(my==0))
      POINT(row-y,col+x,color,xor);
    return;
  }

