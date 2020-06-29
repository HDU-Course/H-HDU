
  #include "stdio.h"
  #include "lerrf.c"
  #include "lgam2.c"
  #include "lgam1.c"
  main()
  { int i,j;
    double x,y;
    printf("\n");
    for (i=0; i<=9; i++)
      { for (j=0; j<=3; j++)
          { x=0.05*(4.0*i+j); y=lerrf(x);
            printf("erf(%4.2f)=%8.6f ",x,y);
          }
        printf("\n");
      }
    x=2.0; y=lerrf(x);
    printf("erf(%4.2f)=%8.6f\n",x,y);
    printf("\n");
  }

