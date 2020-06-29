
  #include "stdlib.h"
  double fgaus(n,js)
  int n,js[];
  { extern void fgauss();
    extern double fgausf();
    int m,j,k,q,l,*is;
    double y[2],p,s,*x,*a,*b;
    static double t[5]={-0.9061798459,-0.5384693101,0.0,
                         0.5384693101,0.9061798459};
    static double c[5]={0.2369268851,0.4786286705,0.5688888889,
                        0.4786286705,0.2369268851};
    is=malloc(2*(n+1)*sizeof(int));
    x=malloc(n*sizeof(double));
    a=malloc(2*(n+1)*sizeof(double));
    b=malloc((n+1)*sizeof(double));
    m=1; l=1;
    a[n]=1.0; a[2*n+1]=1.0;
    while (l==1)
      { for (j=m;j<=n;j++)
          { fgauss(j-1,n,x,y);
            a[j-1]=0.5*(y[1]-y[0])/js[j-1];
            b[j-1]=a[j-1]+y[0];
            x[j-1]=a[j-1]*t[0]+b[j-1];
            a[n+j]=0.0;
            is[j-1]=1; is[n+j]=1;
          }
        j=n; q=1;
        while (q==1)
          { k=is[j-1];
            if (j==n) p=fgausf(n,x);
            else p=1.0;
            a[n+j]=a[n+j+1]*a[j]*p*c[k-1]+a[n+j];
            is[j-1]=is[j-1]+1;
            if (is[j-1]>5)
              if (is[n+j]>=js[j-1])
                { j=j-1; q=1;
                  if (j==0)
                    { s=a[n+1]*a[0]; free(is); free(x);
                      free(a); free(b); return(s);
                    }
                }
              else
                { is[n+j]=is[n+j]+1;
                  b[j-1]=b[j-1]+a[j-1]*2.0;
                  is[j-1]=1; k=is[j-1];
                  x[j-1]=a[j-1]*t[k-1]+b[j-1];
                  if (j==n) q=1;
                  else q=0;
                }
            else
              { k=is[j-1];
                x[j-1]=a[j-1]*t[k-1]+b[j-1];
                if (j==n) q=1;
                else q=0;
              }
          }
        m=j+1;
      }
  }

