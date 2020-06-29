
  #include "math.h"
  void ocmul(a,b,c,d,e,f)
  double a,b,c,d,*e,*f;
  { double p,q,s;
    p=a*c; q=b*d; s=(a+b)*(c+d);
    *e=p-q; *f=s-p-q;
    return;
  }

