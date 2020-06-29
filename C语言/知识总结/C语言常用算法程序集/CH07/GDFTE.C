
  #include "stdlib.h"
  void gdfte(a,b,ya,yb,n,y)
  int n;
  double a,b,ya,yb,y[];
  { extern void gdftef();
    extern int atrde();
    int i,j,k,nn,m1;
    double z[4],h,x,*g,*d;
    g=malloc(6*n*sizeof(double));
    d=malloc(2*n*sizeof(double));
    h=(b-a)/(n-1.0); nn=2*n-1;
    g[0]=1.0; g[1]=0.0;
    y[0]=ya; y[n-1]=yb;
    g[3*n-3]=1.0; g[3*n-4]=0.0;
    for (i=2; i<=n-1; i++)
      { x=a+(i-1)*h;
        gdftef(x,z);
        k=3*(i-1)-1;
        g[k]=z[0]-h*z[1]/2.0;
        g[k+1]=h*h*z[2]-2.0*z[0];
        g[k+2]=z[0]+h*z[1]/2.0;
        y[i-1]=h*h*z[3];
      }
    m1=3*n-2;
    atrde(g,n,m1,y);
    h=h/2.0;
    g[0]=1.0; g[1]=0.0;
    d[0]=ya; d[nn-1]=yb;
    g[3*nn-3]=1.0; g[3*nn-4]=0.0;
    for (i=2; i<=nn-1; i++)
      { x=a+(i-1)*h;
        gdftef(x,z);
        k=3*(i-1)-1;
        g[k]=z[0]-h*z[1]/2.0;
        g[k+1]=h*h*z[2]-2.0*z[0];
        g[k+2]=z[0]+h*z[1]/2.0;
        d[i-1]=h*h*z[3];
      }
    m1=3*nn-2;
    atrde(g,nn,m1,d);
    for (i=2; i<=n-1; i++)
      { k=i+i-1;
        y[i-1]=(4.0*d[k-1]-y[i-1])/3.0;
      }
    free(g); free(d);
    return;
  }

