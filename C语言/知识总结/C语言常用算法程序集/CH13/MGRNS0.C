
  #include "stdio.h"
  #include "mgrns.c"
  main()
  { int i,j;
    double u,g,r,a[50];
    r=3.0; u=1.0; g=1.5;
    printf("\n");
    mgrns(u,g,&r,50,a);
    for (i=0; i<=9; i++)
      { for (j=0; j<=4; j++)
          printf("%10.7lf  ",a[i*5+j]);
        printf("\n");
      }
    printf("\n");
  }

