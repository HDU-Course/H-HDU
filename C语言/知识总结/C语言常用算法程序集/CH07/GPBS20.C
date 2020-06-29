
  #include "stdio.h"
  #include "gpbs2.c"
  main()
  { int i;
    double t,h,eps,z[2][11],y[2];
    t=0.0; h=0.1; eps=0.000001;
    y[0]=1.0; y[1]=0.0;
    printf("\n");
    gpbs2(t,h,2,y,eps,11,z);
    for (i=0; i<=10; i++)
      { t=i*h;
        printf("t=%7.3f  y(0)=%e  y(1)=%e\n",
                t,z[0][i],z[1][i]);
      }
    printf("\n");
  }

  void gpbs2f(t,y,n,d)
  int n;
  double t,y[],d[];
  { t=t; n=n;
    d[0]=-y[1]; d[1]=y[0];
    return;
  }

