
  #include "stdio.h"
  #include "bchol.c"
  main()
  { int i,j;
    double det;
    static double a[4][4]={ {5.0,7.0,6.0,5.0},
                            {7.0,10.0,8.0,7.0},
                            {6.0,8.0,10.0,9.0},
                            {5.0,7.0,9.0,10.0}};
    i=bchol(a,4,&det);
    if (i>0)
      { printf("MAT L IS:\n");
        for (i=0; i<=3; i++)
          { for (j=0; j<=3; j++)
              printf("%13.7e ",a[i][j]);
            printf("\n");
          }
        printf("\n");
        printf("det(A)=%13.7e\n",det);
      }
  }

