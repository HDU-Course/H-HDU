
  #include "math.h"
  int ddhrt(a,b,h,eps,x,m)
  int m;
  double a,b,h,eps,x[];
  { extern double ddhrtf();
    int n,js;
    double z,y,z1,y1,z0,y0;
    n=0; z=a; y=ddhrtf(z);
    while ((z<=b+h/2.0)&&(n!=m))
      { if (fabs(y)<eps)
          { n=n+1; x[n-1]=z;
            z=z+h/2.0; y=ddhrtf(z);
          }
        else
          { z1=z+h; y1=ddhrtf(z1);
            if (fabs(y1)<eps)
              { n=n+1; x[n-1]=z1;
                z=z1+h/2.0; y=ddhrtf(z);
              }
            else if (y*y1>0.0)
              { y=y1; z=z1;}
            else
              { js=0;
                while (js==0)
                  { if (fabs(z1-z)<eps)
                      { n=n+1; x[n-1]=(z1+z)/2.0;
                        z=z1+h/2.0; y=ddhrtf(z);
                        js=1;
                      }
                    else
                      { z0=(z1+z)/2.0; y0=ddhrtf(z0);
                        if (fabs(y0)<eps)
                          { x[n]=z0; n=n+1; js=1;
                            z=z0+h/2.0; y=ddhrtf(z);
                          }
                        else if ((y*y0)<0.0)
                          { z1=z0; y1=y0;}
                        else { z=z0; y=y0;}
                      }
                  }
              }
          }
      }
    return(n);
  }

