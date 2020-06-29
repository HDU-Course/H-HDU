
  #include "stdio.h"
  #include "lexpp.c"
  main()
  { int i;
    double x,y;
    printf("\n");
    for (i=0; i<=9; i++)
      { x=0.05+0.2*i; y=lexpp(x);
        printf("x=%4.2f    Ei(x)=%10.7f\n",x,y);
      }
    printf("\n");
  }

