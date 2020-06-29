
  #include "stdio.h"
  #include "mrabs.c"
  main()
  { int i,j,p[50],r;
    r=1;
    printf("\n");
    mrabs(100,300,&r,p,50);
    for (i=0; i<=4; i++)
      { for (j=0; j<=9; j++)
          printf("%d   ",p[10*i+j]);
        printf("\n");
      }
    printf("\n");
  }

