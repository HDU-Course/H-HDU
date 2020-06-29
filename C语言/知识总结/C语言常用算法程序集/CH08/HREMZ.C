
  #include "math.h"
  void hremz(a,b,p,n,eps)
  int n;
  double a,b,eps,p[];
  { extern double hremzf();
    int i,j,k,m;
    double x[21],g[21],d,t,u,s,xx,x0,h,yy;
    if (n>20) n=20;
    m=n+1; d=1.0e+35;
    for (k=0; k<=n; k++)
      { t=cos((n-k)*3.1415926/(1.0*n));
        x[k]=(b+a+(b-a)*t)/2.0;
      }
    while (1==1)
      { u=1.0;
        for (i=0; i<=m-1; i++)
          { p[i]=hremzf(x[i]);
            g[i]=-u; u=-u;
          }
        for (j=0; j<=n-1; j++)
          { k=m; s=p[k-1]; xx=g[k-1];
            for (i=j; i<=n-1; i++)
              { t=p[n-i+j-1]; x0=g[n-i+j-1];
                p[k-1]=(s-t)/(x[k-1]-x[m-i-2]);
                g[k-1]=(xx-x0)/(x[k-1]-x[m-i-2]);
                k=n-i+j; s=t; xx=x0;
              }
          }
        u=-p[m-1]/g[m-1];
        for (i=0; i<=m-1; i++)
          p[i]=p[i]+g[i]*u;
        for (j=1; j<=n-1; j++)
          { k=n-j; h=x[k-1]; s=p[k-1];
            for (i=m-j; i<=n; i++)
              { t=p[i-1]; p[k-1]=s-h*t;
                s=t; k=i;
              }
          }
        p[m-1]=fabs(u); u=p[m-1];
        if (fabs(u-d)<=eps) return;
        d=u; h=0.1*(b-a)/(1.0*n);
        xx=a; x0=a;
        while (x0<=b)
          { s=hremzf(x0); t=p[n-1];
            for (i=n-2; i>=0; i--)
              t=t*x0+p[i];
            s=fabs(s-t);
            if (s>u) { u=s; xx=x0;}
            x0=x0+h;
          }
        s=hremzf(xx); t=p[n-1];
        for (i=n-2; i>=0; i--)
          t=t*xx+p[i];
        yy=s-t; i=1; j=n+1;
        while ((j-i)!=1)
          { k=(i+j)/2;
            if (xx<x[k-1]) j=k;
            else i=k;
          }
        if (xx<x[0])
          { s=hremzf(x[0]); t=p[n-1];
            for (k=n-2; k>=0; k--)
              t=t*x[0]+p[k];
            s=s-t;
            if (s*yy>0.0) x[0]=xx;
            else
              { for (k=n-1; k>=0; k--)
                  x[k+1]=x[k];
                x[0]=xx;
              }
          }
        else
          { if (xx>x[n])
              { s=hremzf(x[n]); t=p[n-1];
                for (k=n-2; k>=0; k--)
                  t=t*x[n]+p[k];
                s=s-t;
                if (s*yy>0.0) x[n]=xx;
                else
                  { for (k=0; k<=n-1; k++)
                      x[k]=x[k+1];
                    x[n]=xx;
                  }
              }
            else
              { i=i-1; j=j-1;
                s=hremzf(x[i]); t=p[n-1];
                for (k=n-2; k>=0; k--)
                  t=t*x[i]+p[k];
                s=s-t;
                if (s*yy>0.0) x[i]=xx;
                else x[j]=xx;
              }
          }
      }
  }

