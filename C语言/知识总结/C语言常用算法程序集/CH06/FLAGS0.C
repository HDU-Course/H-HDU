
  #include "stdio.h"
  #include "flags.c"
  main()
  { printf("\n");
    printf("g=%e\n",flags());
    printf("\n");
  }

  double flagsf(x)
  double x;
  { double y;
    y=x*exp(-x);
    return(y);
  }

