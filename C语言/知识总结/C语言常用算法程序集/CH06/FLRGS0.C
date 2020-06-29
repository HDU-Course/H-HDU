
  #include "math.h"
  #include "stdio.h"
  #include "flrgs.c"
  main()
  { double a,b,eps,g;
    a=2.5; b=8.4; eps=0.000001;
    g=flrgs(a,b,eps);
    printf("\n");
    printf("g=%e\n",g);
    printf("\n");
  }

  double flrgsf(x)
  double x;
  { double y;
    y=x*x+sin(x);
    return(y);
  }

