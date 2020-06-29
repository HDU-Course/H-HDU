
  #include "stdio.h"
  #include "fffts.c"
  main()
  { double a,b,eps,t;
    a=0.0; b=1.0; eps=0.000001;
    t=fffts(a,b,eps);
    printf("\n");
    printf("t=%e\n",t);
    printf("\n");
  }

  #include "math.h"
  double ffftsf(x)
  double x;
  { double y;
    y=exp(-x*x);
    return(y);
  }

