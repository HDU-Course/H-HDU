
  #include "stdio.h"
  #include "lbsl4.c"
  #include "lbsl3.c"
  main()
  { int n,i;
    double x,y;
    printf("\n");
    for (n=0; n<=5; n++)
      { x=0.05;
        for (i=1; i<=4; i++)
          { y=lbsl4(n,x);
            printf("n=%d   x=%6.3f   K(n,x)=%e\n",n,x,y);
            x=x*10.0;
          }
      }
    printf("\n");
  }

