
  #include "math.h"
  void jmax1(x,eps,k,js)
  int k,js[2];
  double eps,x[2];
  { extern void jmax1f();
    int i,j,m,jt;
    double xx,h1,h2,dx,y[10],b[10],z[2];
    js[0]=0; jt=1; h2=0.0;
    while (jt==1)
      { j=0;
        while (j<=7)
          { if (j<=2) xx=x[0]+0.01*j;
            else xx=h2;
            jmax1f(xx,z);
            if (fabs(z[1])<eps)
              { jt=0; j=10;}
            else
              { h1=z[1]; h2=xx;
                if (j==0) { y[0]=h1; b[0]=h2;}
                else
                  { y[j]=h1; m=0; i=0;
                    while ((m==0)&&(i<=j-1))
			{ if (fabs(h2-b[i])+1.0==1.0) m=1;
			  else h2=(h1-y[i])/(h2-b[i]);
                          i=i+1;
			}
                    b[j]=h2;
                    if (m!=0) b[j]=1.0e+35;
                    h2=0.0;
                    for (i=j-1; i>=0; i--)
                      h2=-y[i]/(b[i+1]+h2);
                    h2=h2+b[0];
                  }
                j=j+1;
              }
          }
        x[0]=h2;
        js[0]=js[0]+1;
        if (js[0]==k)  jt=0;
      }
    xx=x[0];
    jmax1f(xx,z); x[1]=z[0];
    if (fabs(x[0])<=1.0) dx=1.0e-05;
    else dx=fabs(x[0]*1.0e-05);
    xx=x[0]-dx;
    jmax1f(xx,z); h1=z[0];
    xx=x[0]+dx;
    jmax1f(xx,z); h2=z[0];
    js[1]=-1;
    if ((h1+h2-2.0*x[1])<=0.0) js[1]=1;
    return;
  }

