
  #include "math.h"
  double lsinn(x)
  double x;
  { int m,i,j;
    double s,p,ep,h,aa,bb,w,xx,g;
    static double t[5]={-0.9061798459,-0.5384693101,0.0,
                         0.5384693101,0.9061798459};
    static double c[5]={0.2369268851,0.4786286705,0.5688888889,
                        0.4786286705,0.2369268851};
    m=1;
    if (x==0) return(0.0);
    h=fabs(x);  s=fabs(0.0001*h);
    p=1.0e+35; ep=0.000001; g=0.0;
    while ((ep>=0.0000001)&&(fabs(h)>s))
      { g=0.0;
        for (i=1;i<=m;i++)
          { aa=(i-1.0)*h; bb=i*h;
            w=0.0;
            for (j=0;j<=4;j++)
              { xx=((bb-aa)*t[j]+(bb+aa))/2.0;
                w=w+sin(xx)/xx*c[j];
              }
            g=g+w;
          }
        g=g*h/2.0;
        ep=fabs(g-p)/(1.0+fabs(g));
        p=g; m=m+1; h=fabs(x)/m;
      }
    return(g);
  }

