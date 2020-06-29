
  #include "stdio.h"
  #include "lgam1.c"
  main()
  { int i;
    double x,y;
    printf("\n");
    for (i=1; i<=10; i++)
      { x=0.5*i; y=lgam1(x);
        printf("x=%6.3f  gamma(x)=%e\n",x,y);
      }
    printf("\n");
    y=lgam1(1.5)*lgam1(2.5)/lgam1(4.0);
    printf("B(1.5,2.5)=%e\n",y);
    printf("\n");
  }

