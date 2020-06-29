
  #include "stdio.h"
  #include "blluu.c"
  main()
  { int i,j;
    static double l[4][4],u[4][4];
    static double a[4][4]={ {2.0,4.0,4.0,2.0},
                            {3.0,3.0,12.0,6.0},
                            {2.0,4.0,-1.0,2.0},
                            {4.0,2.0,1.0,1.0}};
    i=blluu(a,4,l,u);
    if (i!=0)
      { printf("MAT L IS:\n");
        for (i=0; i<=3; i++)
          { for (j=0; j<=3; j++)
              printf("%13.7e ",l[i][j]);
            printf("\n");
          }
        printf("\n");
        printf("MAT U IS:\n");
        for (i=0; i<=3; i++)
          { for (j=0; j<=3; j++)
              printf("%13.7e ",u[i][j]);
            printf("\n");
          }
        printf("\n");
      }
  }

