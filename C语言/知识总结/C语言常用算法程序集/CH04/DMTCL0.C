
  #include "math.h"
  #include "stdio.h"
  #include "dmtcl.c"
  #include "mrnd1.c"
  main()
  { int m;
    double x,b,eps;
    x=0.5; b=1.0; m=10; eps=0.00001;
    dmtcl(&x,b,m,eps);
    printf("\n");
    printf("x=%13.7e\n",x);
    printf("\n");
  }

  double dmtclf(x)
  double x;
  { double y;
    y=exp(-x*x*x)-sin(x)/cos(x)+800.0;
    return(y);
  }

