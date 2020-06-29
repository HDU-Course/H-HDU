
  #include "math.h"
  void enspl(x,y,n,k,t,s)
  int n,k;
  double t,x[],y[],s[5];
  { int kk,m,l;
    double u[5],p,q;
    s[4]=0.0; s[0]=0.0; s[1]=0.0; s[2]=0.0; s[3]=0.0;
    if (n<1) return;
    if (n==1) { s[0]=y[0]; s[4]=y[0]; return;}
    if (n==2)
      { s[0]=y[0]; s[1]=(y[1]-y[0])/(x[1]-x[0]);
        if (k<0)
          s[4]=(y[0]*(t-x[1])-y[1]*(t-x[0]))/(x[0]-x[1]);
        return;
      }
    if (k<0)
      { if (t<=x[1]) kk=0;
        else if (t>=x[n-1]) kk=n-2;
        else
          { kk=1; m=n;
            while (((kk-m)!=1)&&((kk-m)!=-1))
              { l=(kk+m)/2;
                if (t<x[l-1]) m=l;
                else kk=l;
              }
            kk=kk-1;
          }
      }
    else kk=k;
    if (kk>=n-1) kk=n-2;
    u[2]=(y[kk+1]-y[kk])/(x[kk+1]-x[kk]);
    if (n==3)
      { if (kk==0)
          { u[3]=(y[2]-y[1])/(x[2]-x[1]);
            u[4]=2.0*u[3]-u[2];
            u[1]=2.0*u[2]-u[3];
            u[0]=2.0*u[1]-u[2];
          }
        else
          { u[1]=(y[1]-y[0])/(x[1]-x[0]);
            u[0]=2.0*u[1]-u[2];
            u[3]=2.0*u[2]-u[1];
            u[4]=2.0*u[3]-u[2];
          }
      }
    else
      { if (kk<=1)
          { u[3]=(y[kk+2]-y[kk+1])/(x[kk+2]-x[kk+1]);
            if (kk==1)
              { u[1]=(y[1]-y[0])/(x[1]-x[0]);
                u[0]=2.0*u[1]-u[2];
                if (n==4) u[4]=2.0*u[3]-u[2];
                else u[4]=(y[4]-y[3])/(x[4]-x[3]);
              }
            else
              { u[1]=2.0*u[2]-u[3];
                u[0]=2.0*u[1]-u[2];
                u[4]=(y[3]-y[2])/(x[3]-x[2]);
              }
          }
        else if (kk>=(n-3))
          { u[1]=(y[kk]-y[kk-1])/(x[kk]-x[kk-1]);
            if (kk==(n-3))
              { u[3]=(y[n-1]-y[n-2])/(x[n-1]-x[n-2]);
                u[4]=2.0*u[3]-u[2];
                if (n==4) u[0]=2.0*u[1]-u[2];
                else u[0]=(y[kk-1]-y[kk-2])/(x[kk-1]-x[kk-2]);
              }
            else
              { u[3]=2.0*u[2]-u[1];
                u[4]=2.0*u[3]-u[2];
                u[0]=(y[kk-1]-y[kk-2])/(x[kk-1]-x[kk-2]);
              }
          }
        else
          { u[1]=(y[kk]-y[kk-1])/(x[kk]-x[kk-1]);
            u[0]=(y[kk-1]-y[kk-2])/(x[kk-1]-x[kk-2]);
            u[3]=(y[kk+2]-y[kk+1])/(x[kk+2]-x[kk+1]);
            u[4]=(y[kk+3]-y[kk+2])/(x[kk+3]-x[kk+2]);
          }
      }
    s[0]=fabs(u[3]-u[2]);
    s[1]=fabs(u[0]-u[1]);
    if ((s[0]+1.0==1.0)&&(s[1]+1.0==1.0))
         p=(u[1]+u[2])/2.0;
    else p=(s[0]*u[1]+s[1]*u[2])/(s[0]+s[1]);
    s[0]=fabs(u[3]-u[4]);
    s[1]=fabs(u[2]-u[1]);
    if ((s[0]+1.0==1.0)&&(s[1]+1.0==1.0))
         q=(u[2]+u[3])/2.0;
    else q=(s[0]*u[2]+s[1]*u[3])/(s[0]+s[1]);
    s[0]=y[kk];
    s[1]=p;
    s[3]=x[kk+1]-x[kk];
    s[2]=(3.0*u[2]-2.0*p-q)/s[3];
    s[3]=(q+p-2.0*u[2])/(s[3]*s[3]);
    if (k<0)
      { p=t-x[kk];
        s[4]=s[0]+s[1]*p+s[2]*p*p+s[3]*p*p*p;
      }
    return;
  }

