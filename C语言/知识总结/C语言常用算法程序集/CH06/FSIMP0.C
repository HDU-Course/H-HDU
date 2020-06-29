
  #include "stdio.h"
  #include "fsimp.c"
  main()
  { double a,b,eps,t;
    a=0.0; b=1.0; eps=0.000001;
    t=fsimp(a,b,eps);
    printf("\n");
    printf("t=%e\n",t);
    printf("\n");
  }

  #include "math.h"
  double fsimpf(x)
  double x;
  { double y;
    y=log(1.0+x)/(1.0+x*x);
    return(y);
  }

