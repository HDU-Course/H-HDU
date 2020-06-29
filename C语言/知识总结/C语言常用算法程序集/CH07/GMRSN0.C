
  #include "stdio.h"
  #include "gmrsn.c"
  main()
  { int i;
    double t,h,eps,x,y[2],z[2][11];
    t=0.0; h=0.1; eps=0.00001;
    y[0]=0.0; y[1]=1.0;
    gmrsn(t,h,2,y,eps,11,z);
    printf("\n");
    for (i=0; i<=10; i++)
      { x=i*h;
        printf("t=%7.3f  y(0)=%e  y(1)=%e\n",
               x,z[0][i],z[1][i]);
      }
    printf("\n");
  }

  void gmrsnf(t,y,n,d)
  int n;
  double t,y[],d[];
  { double q;
    n=n;
    q=60.0*(0.06+t*(t-0.6));
    d[0]=q*y[1]; d[1]=-q*y[0];
    return;
  }

