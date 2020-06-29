
  #include "math.h"
  #include "stdio.h"
  #include "dnewt.c"
  main()
  { int js,k;
    double x,eps;
    eps=0.000001; js=60; x=1.5;
    k=dnewt(&x,eps,js);
    if (k>=0)
      printf("k=%d  x=%13.7e\n",k,x);
    printf("\n");
  }

  void dnewtf(x,y)
  double x,y[2];
  { y[0]=x*x*(x-1.0)-1.0;
    y[1]=3.0*x*x-2.0*x;
    return;
  }

