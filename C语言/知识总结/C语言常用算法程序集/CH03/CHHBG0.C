
  #include "stdio.h"
  #include "chhbg.c"
  main()
  { int i,j;
    static double a[5][5]={ {1.0,6.0,-3.0,-1.0,7.0},
      {8.0,-15.0,18.0,5.0,4.0},{-2.0,11.0,9.0,15.0,20.0},
      {-13.0,2.0,21.0,30.0,-6.0},{17.0,22.0,-5.0,3.0,6.0}};
    chhbg(a,5);
    printf("MAT A IS:\n");
    for (i=0; i<=4; i++)
      { for (j=0; j<=4; j++)
          printf("%13.7e ",a[i][j]);
        printf("\n");
      }
    printf("\n");
  }

