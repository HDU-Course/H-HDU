
  #include "stdio.h"
  #include "fmtcl.c"
  #include "mrnd1.c"
  main()
  { printf("\n");
    printf("s=%e\n",fmtcl(2.5,8.4));
    printf("\n");
  }

  double fmtclf(x)
  double x;
  { double y;
    y=x*x+sin(x);
    return(y);
  }

