
  #include "math.h"
  #include "stdio.h"
  #include "fcbsv.c"
  main()
  { double a,b,eps,s;
    a=2.5; b=8.4; eps=0.000001;
    s=fcbsv(a,b,eps);
    printf("\n");
    printf("s=%e\n",s);
    printf("\n");
  }

  double fcbsvf(x)
  double x;
  { double y;
    y=x*x+sin(x);
    return(y);
  }

