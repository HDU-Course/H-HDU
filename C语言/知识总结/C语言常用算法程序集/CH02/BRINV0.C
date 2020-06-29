
  #include "stdio.h"
  #include "brinv.c"
  #include "brmul.c"
  main()
  { int i,j;
    static double a[4][4]={ {0.2368,0.2471,0.2568,1.2671},
                            {1.1161,0.1254,0.1397,0.1490},
                            {0.1582,1.1675,0.1768,0.1871},
                            {0.1968,0.2071,1.2168,0.2271}};
    static double b[4][4],c[4][4];
    for (i=0; i<=3; i++)
    for (j=0; j<=3; j++)
      b[i][j]=a[i][j];
    i=brinv(a,4);
    if (i!=0)
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
      }
  }

