
  #include "math.h"
  #include "stdio.h"
  #include "fpqg2.c"
  main()
  { double a,b,eps,s;
    a=0.0; b=1.0; eps=0.00005;
    s=fpqg2(a,b,eps);
    printf("\n");
    printf("s=%e\n",s);
    printf("\n");
  }

  void fpqg2s(x,y)
  double x,y[2];
  { y[1]=sqrt(1.0-x*x);
    y[0]=-y[1];
    return;
  }

  double fpqg2f(x,y)
  double x,y;
  { double z;
    z=exp(x*x+y*y);
    return(z);
  }

