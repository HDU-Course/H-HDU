
  #include "math.h"
  double lbsl4(n,x)
  int n;
  double x;
  { int i;
    double y,p,b0,b1;
    extern double lbsl3();
    static double a[7]={ -0.57721566,0.4227842,0.23069756,
           0.0348859,0.00262698,0.0001075,0.0000074};
    static double b[7]={ 1.0,0.15443144,-0.67278579,
           -0.18156897,-0.01919402,-0.00110404,-0.00004686};
    static double c[7]={ 1.25331414,-0.07832358,0.02189568,
           -0.01062446,0.00587872,-0.0025154,0.00053208};
    static double d[7]={ 1.25331414,0.23498619,-0.0365562,
           0.01504268,-0.00780353,0.00325614,-0.00068245};
    if (n<0) n=-n;
    if (x<0.0) x=-x;
    if (x==0.0) return(1.0e+70);
    if (n!=1)
      { if (x<=2.0)
          { y=x*x/4.0; p=a[6];
            for (i=5; i>=0; i--) p=p*y+a[i];
            p=p-lbsl3(0,x)*log(x/2.0);
          }
        else
          { y=2.0/x; p=c[6];
            for (i=5; i>=0; i--) p=p*y+c[i];
            p=p*exp(-x)/sqrt(x);
          }
      }
    if (n==0) return(p);
    b0=p;
    if (x<=2.0)
      { y=x*x/4.0; p=b[6];
        for (i=5; i>=0; i--) p=p*y+b[i];
        p=p/x+lbsl3(1,x)*log(x/2.0);
      }
    else
      { y=2.0/x; p=d[6];
        for (i=5; i>=0; i--) p=p*y+d[i];
        p=p*exp(-x)/sqrt(x);
      }
    if (n==1) return(p);
    b1=p;
    y=2.0/x;
    for (i=1; i<n; i++)
      { p=b0+i*y*b1; b0=b1; b1=p;}
    return(p);
  }

