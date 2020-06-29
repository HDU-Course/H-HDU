
  #include "stdio.h"
  #include "mrnds.c"
  main()
  { int i,j;
    double p[50],r;
    r=1.0; 
    mrnds(&r,p,50);
    printf("\n");
    for (i=0; i<=9; i++)
      { for (j=0; j<=4; j++)
          printf("%10.7lf  ",p[5*i+j]);
        printf("\n");
      }
    printf("\n");
  }

