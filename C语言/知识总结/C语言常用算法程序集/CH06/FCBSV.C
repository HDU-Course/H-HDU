
  #include "math.h"
  double fcbsv(a,b,eps)
  double a,b,eps;
  { extern double fcbsvf();
    int m,i,j;
    double h,d,p,ep,g,aa,bb,s,x;
    static double t[5]={-0.8324975,-0.3745414,0.0,
                         0.3745414,0.8324975};
    m=1;
    h=b-a; d=fabs(0.001*h);
    p=1.0e+35; ep=1.0+eps;
    while ((ep>=eps)&&(fabs(h)>d))
      { g=0.0;
        for (i=1;i<=m;i++)
          { aa=a+(i-1.0)*h; bb=a+i*h;
            s=0.0;
            for (j=0;j<=4;j++)
              { x=((bb-aa)*t[j]+(bb+aa))/2.0;
                s=s+fcbsvf(x);
              }
            g=g+s;
          }
        g=g*h/5.0;
        ep=fabs(g-p)/(1.0+fabs(g));
        p=g; m=m+1; h=(b-a)/m;
      }
    return(g);
  }

