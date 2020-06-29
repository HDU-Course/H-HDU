
  #include "math.h"
  #include "stdio.h"
  #include "ffpqg.c"
  main()
  { double a,b,eps,s;
    a=0.0; b=4.3; eps=0.000001;
    s=ffpqg(a,b,eps);
    printf("\n");
    printf("s=%e\n",s);
    printf("\n");
  }

  double ffpqgf(x)
  double x;
  { double y;
    y=exp(-x*x);
    return(y);
  }

