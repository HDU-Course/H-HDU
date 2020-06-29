
  #include "math.h"
  #include "stdio.h"
  #include "fsim2.c"
  main()
  { double a,b,eps,s;
    a=0.0; b=1.0; eps=0.0001;
    s=fsim2(a,b,eps);
    printf("\n");
    printf("s=%e\n",s);
    printf("\n");
  }

  void fsim2s(x,y)
  double x,y[2];
  { y[0]=-sqrt(1.0-x*x);
    y[1]=-y[0];
    return;
  }

  double fsim2f(x,y)
  double x,y;
  { double z;
    z=exp(x*x+y*y);
    return(z);
  }

