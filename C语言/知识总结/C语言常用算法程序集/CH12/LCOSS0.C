
  #include "stdio.h"
  #include "lcoss.c"
  main()
  { int i;
    double x,y;
    printf("\n");
    for (i=0; i<=9; i++)
      { x=0.5+i+i; y=lcoss(x);
        printf("x=%4.2f    Ci(x)=%10.7f\n",x,y);
      }
    printf("\n");
  }

