
  #include "stdio.h"
  #include "mrab1.c"
  main()
  { int i,j,r;
    r=5; 
    printf("\n");
    for (i=0; i<=4; i++)
      { for (j=0; j<=9; j++)
          printf("%d   ",mrab1(101,200,&r));
        printf("\n");
      }
    printf("\n");
  }

