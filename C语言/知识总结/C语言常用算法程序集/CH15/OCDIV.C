
  #include "math.h"
  void ocdiv(a,b,c,d,e,f)
  double a,b,c,d,*e,*f;
  { double p,q,s,w;
    p=a*c; q=-b*d; s=(a+b)*(c-d);
    w=c*c+d*d;
    if (w+1.0==1.0) 
      { *e=1.0e+35*a/fabs(a);
        *f=1.0e+35*b/fabs(b);
      }
    else
      { *e=(p-q)/w; *f=(s-p-q)/w; }
    return;
  }

