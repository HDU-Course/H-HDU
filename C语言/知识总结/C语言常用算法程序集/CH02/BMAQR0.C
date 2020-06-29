
  #include "stdio.h"
  #include "bmaqr.c"
  main()
  { int i,j;
    static double q[4][4],a[4][3]={ {1.0,1.0,-1.0},
       {2.0,1.0,0.0},{1.0,-1.0,0.0},{-1.0,2.0,1.0}};
    i=bmaqr(a,4,3,q);
    if (i!=0)
      { printf("MAT Q IS:\n");
        for (i=0; i<=3; i++)
          { for (j=0; j<=3; j++)
              printf("%13.7e ",q[i][j]);
            printf("\n");
          }
        printf("\n");
        printf("MAT R IS:\n");
        for (i=0; i<=3; i++)
          { for (j=0; j<=2; j++)
              printf("%13.7e ",a[i][j]);
            printf("\n");
          }
        printf("\n");
      }
  }

