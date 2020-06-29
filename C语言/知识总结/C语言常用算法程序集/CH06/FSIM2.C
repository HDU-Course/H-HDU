
  #include "math.h"
  double fsim2(a,b,eps)
  double a,b,eps;
  { double simp1();
    int n,j;
    double h,d,s1,s2,t1,x,t2,g,s,s0,ep;
    n=1; h=0.5*(b-a);
    d=fabs((b-a)*1.0e-06);
    s1=simp1(a,eps); s2=simp1(b,eps);
    t1=h*(s1+s2);
    s0=1.0e+35; ep=1.0+eps;
    while (((ep>=eps)&&(fabs(h)>d))||(n<16))
      { x=a-h; t2=0.5*t1;
        for (j=1;j<=n;j++)
          { x=x+2.0*h;
            g=simp1(x,eps);
            t2=t2+h*g;
          }
        s=(4.0*t2-t1)/3.0;
        ep=fabs(s-s0)/(1.0+fabs(s));
        n=n+n; s0=s; t1=t2; h=h*0.5;
      }
    return(s);
  }

  static double simp1(x,eps)
  double x,eps;
  { extern void fsim2s();
    extern double fsim2f();
    int n,i;
    double y[2],h,d,t1,yy,t2,g,ep,g0;
    n=1;
    fsim2s(x,y);
    h=0.5*(y[1]-y[0]);
    d=fabs(h*2.0e-06);
    t1=h*(fsim2f(x,y[0])+fsim2f(x,y[1]));
    ep=1.0+eps; g0=1.0e+35;
    while (((ep>=eps)&&(fabs(h)>d))||(n<16))
      { yy=y[0]-h;
        t2=0.5*t1;
        for (i=1;i<=n;i++)
          { yy=yy+2.0*h;
            t2=t2+h*fsim2f(x,yy);
          }
        g=(4.0*t2-t1)/3.0;
        ep=fabs(g-g0)/(1.0+fabs(g));
        n=n+n; g0=g; t1=t2; h=0.5*h;
      }
    return(g);
  }

