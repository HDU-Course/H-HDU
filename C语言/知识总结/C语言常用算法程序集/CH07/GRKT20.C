
  #include "stdio.h"
  #include "grkt2.c"
  main()
  { int i;
    double t,h,eps,y[2];
    y[0]=0.0; y[1]=1.0;
    t=0.0; h=0.1; eps=0.00001;
    printf("\n");
    printf("t=%7.3f  y(0)=%e  y(1)=%e\n",t,y[0],y[1]);
    for (i=1; i<=10; i++)
      { grkt2(t,h,y,2,eps);
        t=t+h;
        printf("t=%7.3f  y(0)=%e  y(1)=%e\n",t,y[0],y[1]);
      }
  }

  void grkt2f(t,y,n,d)
  int n;
  double t,y[],d[];
  { t=t; n=n;
    d[0]=y[1]; d[1]=-y[0];
    return;
  }

