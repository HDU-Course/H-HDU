
  #include "math.h"
  double lelp1(k,f)
  double k,f;
  { int n;
    double pi,y,e,ff;
    double fk();
    if (k<0.0) k=-k;
    if (k>1.0) k=1.0/k;
    pi=3.1415926; y=fabs(f);
    n=0;
    while (y>=pi)
      { n=n+1; y=y-pi;}
    e=1.0;
    if (y>=pi/2.0)
      { n=n+1; e=-e; y=pi-y;}
    if (n==0)
      ff=fk(k,y);
    else
      { ff=fk(k,pi/2.0);
        ff=2.0*n*ff+e*fk(k,y);
      }
    if (f<0.0) ff=-ff;
    return(ff);
  }

  static double fk(k,f)
  double k,f;
  { int m,i,j;
    double s,p,ep,h,aa,bb,w,xx,g,q;
    static double t[5]={-0.9061798459,-0.5384693101,0.0,
                         0.5384693101,0.9061798459};
    static double c[5]={0.2369268851,0.4786286705,0.5688888889,
                        0.4786286705,0.2369268851};
    m=1; g=0.0;
    h=fabs(f); s=fabs(0.0001*h);
    p=1.0e+35; ep=0.000001;
    while ((ep>=0.0000001)&&(fabs(h)>s))
      { g=0.0;
        for (i=1;i<=m;i++)
          { aa=(i-1.0)*h; bb=i*h;
            w=0.0;
            for (j=0;j<=4;j++)
              { xx=((bb-aa)*t[j]+(bb+aa))/2.0;
                q=sqrt(1.0-k*k*sin(xx)*sin(xx));
                w=w+c[j]/q;
              }
            g=g+w;
          }
        g=g*h/2.0;
        ep=fabs(g-p)/(1.0+fabs(g));
        p=g; m=m+m; h=0.5*h;
      }
    return(g);
  }

