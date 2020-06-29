
  #include "math.h"
  #include "stdio.h"
  #include "hremz.c"
  main()
  { int i;
    double a,b,eps,p[5];
    a=-1.0; b=1.0; eps=1.0e-10;
    hremz(a,b,p,4,eps);
    printf("\n");
    for (i=0; i<=3; i++)
      printf("p(%2d)=%e\n",i,p[i]);
    printf("\n");
    printf("MAX(p-f)=%e\n",p[4]);
    printf("\n");
  }

  double hremzf(x)
  double x;
  { double y;
    y=exp(x);
    return(y);
  }

