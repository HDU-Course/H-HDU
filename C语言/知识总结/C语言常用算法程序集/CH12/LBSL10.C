
  #include "stdio.h"
  #include "lbsl1.c"
  main()
  { int n,i;
    double x,y;
    printf("\n");
    for (n=0; n<=5; n++)
      { x=0.05;
        for (i=1; i<=4; i++)
          { y=lbsl1(n,x);
            printf("n=%d   x=%6.3f   J(n,x)=%12.7f\n",n,x,y);
            x=x*10.0;
          }
      }
    printf("\n");
  }

