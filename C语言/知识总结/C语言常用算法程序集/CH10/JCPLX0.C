
  #include "stdio.h"
  #include "jcplx.c"
  main()
  { int i;
    double alpha,eps,a[2],b[2],x[3],xx[3][4];
    x[0]=0.0; x[1]=0.0;
    a[0]=0.0; a[1]=0.0;
    b[0]=1.0e+35; b[1]=b[0];
    eps=1.0e-30; alpha=1.3;
    i=jcplx(2,2,a,b,alpha,eps,x,xx,200);
    printf("\n");
    printf("i=%4d\n",i);
    printf("\n");
    for (i=0; i<=3; i++)
      printf("x(0)=%e  x(1)=%e  f=%e\n",
              xx[0][i],xx[1][i],xx[2][i]);
    printf("\n");
    for (i=0; i<=1; i++)
      printf("x(%2d)=%e\n",i,x[i]);
    printf("J=%e\n",x[2]);
    printf("\n");
  }

  #include "math.h"
  double jcplxf(x,n)
  int n;
  double x[];
  { double y;
    n=n;
    y=-(9.0-(x[0]-3.0)*(x[0]-3.0));
    y=y*x[1]*x[1]*x[1]/(27.0*sqrt(3.0));
    return(y);
  }

  #include "math.h"
  void jcplxs(n,m,x,c,d,w)
  int n,m;
  double x[],c[],d[],w[];
  { n=n; m=m;
    c[0]=0.0; c[1]=0.0;
    d[0]=x[0]/sqrt(3.0); d[1]=6.0;
    w[0]=x[1]; w[1]=x[0]+x[1]*sqrt(3.0);
    return;
  }

