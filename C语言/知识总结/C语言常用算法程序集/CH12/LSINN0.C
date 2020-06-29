
  #include "stdio.h"
  #include "lsinn.c"
  main()
  { int i;
    double x,y;
    printf("\n");
    for (i=0; i<=9; i++)
      { x=0.5+i+i; y=lsinn(x);
        printf("x=%4.2f    Si(x)=%10.7f\n",x,y);
      }
    printf("\n");
  }

