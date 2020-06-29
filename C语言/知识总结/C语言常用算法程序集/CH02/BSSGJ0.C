
  #include "stdio.h"
  #include "bssgj.c"
  #include "brmul.c"
  main()
  { int i,j;
    static double a[4][4]={ {5.0,7.0,6.0,5.0},
                            {7.0,10.0,8.0,7.0},
                            {6.0,8.0,10.0,9.0},
                            {5.0,7.0,9.0,10.0}};
    static double b[4][4],c[4][4];
    for (i=0; i<=3; i++)
    for (j=0; j<=3; j++)
      b[i][j]=a[i][j];
    i=bssgj(a,4);
    if (i>0)
      { printf("MAT A IS:\n");
        for (i=0; i<=3; i++)
          { for (j=0; j<=3; j++)
              printf("%13.7e ",b[i][j]);
            printf("\n");
          }
        printf("\n");
        printf("MAT A- IS:\n");
        for (i=0; i<=3; i++)
          { for (j=0; j<=3; j++)
              printf("%13.7e ",a[i][j]);
            printf("\n");
          }
        printf("\n");
        printf("MAT AA- IS:\n");
        brmul(b,a,4,4,4,c);
        for (i=0; i<=3; i++)
          { for (j=0; j<=3; j++)
              printf("%13.7e ",c[i][j]);
            printf("\n");
          }
        printf("\n");
      }
  }

