
  #include "math.h"
  void dcmtc(x,y,b,m,eps)
  int m;
  double *x,*y,b,eps;
  { extern double mrnd1();
    extern double dcmtcf();
    int k;
    double xx,yy,a,r,z,x1,y1,z1;
    a=b; k=1; r=1.0; xx=*x; yy=*y;
    z=dcmtcf(xx,yy);
    while (a>=eps)
      { x1=-a+2.0*a*mrnd1(&r); x1=xx+x1; 
        y1=-a+2.0*a*mrnd1(&r); y1=yy+y1;
        z1=dcmtcf(x1,y1);
        k=k+1;
        if (z1>=z)
          { if (k>m) { k=1; a=a/2.0; }}
        else
          { k=1; xx=x1; yy=y1;  z=z1;
            if (z<eps)
              { *x=xx; *y=yy; return; }
          }
      }
    *x=xx; *y=yy; return;
  }

