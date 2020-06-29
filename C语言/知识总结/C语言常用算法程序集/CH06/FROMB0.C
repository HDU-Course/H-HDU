
  #include "stdio.h"
  #include "fromb.c"
  main()
  { double a,b,eps,t;
    a=0.0; b=1.0; eps=0.000001;
    t=fromb(a,b,eps);
    printf("\n");
    printf("t=%e\n",t);
    printf("\n");
  }

  double frombf(x)
  double x;
  { double y;
    y=x/(4.0+x*x);
    return(y);
  }

