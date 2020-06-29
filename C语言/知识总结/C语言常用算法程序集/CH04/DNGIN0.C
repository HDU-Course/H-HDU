
  #include "stdio.h"
  #include "agmiv.c"
  #include "bginv.c"
  #include "bmuav.c"
  #include "dngin.c"
  main()
  { int m,n,i,ka;
    double eps1,eps2;
    static double x[2]={0.5,-1.0};
    m=2; n=2; ka=3; eps1=0.000001; eps2=0.000001;
    i=dngin(m,n,eps1,eps2,x,ka);
    printf("\n");
    printf("i=%d\n",i);
    printf("\n");
    for (i=0; i<=1; i++)
      printf("x(%d)=%13.7e\n",i,x[i]);
    printf("\n");
  }

  void dnginf(m,n,x,d)
  int m,n;
  double x[],d[];
  { m=m; n=n;
    d[0]=x[0]*x[0]+10.0*x[0]*x[1]+4.0*x[1]*x[1]+0.7401006;
    d[1]=x[0]*x[0]-3.0*x[0]*x[1]+2.0*x[1]*x[1]-1.0201228;
    return;
  }

  void dngins(m,n,x,p)
  int m,n;
  double x[2],p[2][2];
  { m=m; n=n;
    p[0][0]=2.0*x[0]+10.0*x[1];
    p[0][1]=10.0*x[0]+8.0*x[1];
    p[1][0]=2.0*x[0]-3.0*x[1];
    p[1][1]=-3.0*x[0]+4.0*x[1];
    return;
  }

