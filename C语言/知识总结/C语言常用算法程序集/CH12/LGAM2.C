
  #include "stdio.h"
  #include "math.h"
  double lgam2(a,x)
  double a,x;
  { int n;
    double p,q,d,s,s1,p0,q0,p1,q1,qq;
    extern double lgam1();
    if ((a<=0.0)||(x<0.0))
      { if (a<=0.0) printf("err**a<=0!\n");
        if (x<0.0) printf("err**x<0!\n");
        return(-1.0);
      }
    if (x+1.0==1.0) return(0.0);
    if (x>1.0e+35) return(1.0);
    q=log(x); q=a*q; qq=exp(q);
    if (x<1.0+a)
      { p=a; d=1.0/a; s=d;
        for (n=1; n<=100; n++)
          { p=1.0+p; d=d*x/p; s=s+d;
	    if (fabs(d)<fabs(s)*1.0e-07)
              { s=s*exp(-x)*qq/lgam1(a);
                return(s);
              }
          }
      }
    else
      { s=1.0/x; p0=0.0; p1=1.0; q0=1.0; q1=x;
        for (n=1; n<=100; n++)
          { p0=p1+(n-a)*p0; q0=q1+(n-a)*q0;
            p=x*p0+n*p1; q=x*q0+n*q1;
            if (fabs(q)+1.0!=1.0)
              { s1=p/q; p1=p; q1=q;
                if (fabs((s1-s)/s1)<1.0e-07)
                  { s=s1*exp(-x)*qq/lgam1(a);
                    return(1.0-s);
                  }
                s=s1;
              }
            p1=p; q1=q;
          }
      }
    printf("a too large !\n");
    s=1.0-s*exp(-x)*qq/lgam1(a);
    return(s);
  }


