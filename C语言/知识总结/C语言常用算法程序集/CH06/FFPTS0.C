
  #include "stdio.h"
  #include "ffpts.c"
  main()
  { double a,b,eps,t,d;
    a=-1.0; b=1.0; eps=0.000001; d=0.0001;
    t=ffpts(a,b,eps,d);
    printf("\n");
    printf("t=%e\n",t);
    printf("\n");
  }

  double ffptsf(x)
  double x;
  { double y;
    y=1.0/(1.0+25.0*x*x);
    return(y);
  }

