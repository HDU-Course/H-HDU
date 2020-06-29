
  #include "stdio.h"
  #include "fhmgs.c"
  main()
  { printf("\n");
    printf("g=%e\n",fhmgs());
    printf("\n");
  }

  double fhmgsf(x)
  double x;
  { double y;
    y=x*x*exp(-x*x);
    return(y);
  }

