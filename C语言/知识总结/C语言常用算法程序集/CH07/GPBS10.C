
  #include "stdio.h"
  #include "gpbs1.c"
  main()
  { int i;
    double t,h,eps,y[2];
    t=0.0; h=0.1; eps=0.000001;
    y[0]=1.0; y[1]=0.0;
    printf("\n");
    printf("t=%7.3f  y(0)=%e  y(1)=%e\n",t,y[0],y[1]);
    for (i=0; i<=9; i++)
      { gpbs1(t,h,2,y,eps);
        t=t+h;
        printf("t=%7.3f  y(0)=%e  y(1)=%e\n",t,y[0],y[1]);
      }
    printf("\n");
  }

  void gpbs1f(t,y,n,d)
  int n;
  double t,y[],d[];
  { t=t; n=n;
    d[0]=-y[1]; d[1]=y[0];
    return;
  }

