
  #include "stdio.h"
  #include "bcinv.c"
  #include "bcmul.c"
  main()
  { int i,j;
    static double br[4][4],bi[4][4],cr[4][4],ci[4][4];
    static double ar[4][4]={ {0.2368,0.2471,0.2568,1.2671},
                             {1.1161,0.1254,0.1397,0.1490},
                             {0.1582,1.1675,0.1768,0.1871},
                             {0.1968,0.2071,1.2168,0.2271}};
    static double ai[4][4]={ {0.1345,0.1678,0.1875,1.1161},
                             {1.2671,0.2017,0.7024,0.2721},
                             {-0.2836,-1.1967,0.3558,-0.2078},
                             {0.3576,-1.2345,2.1185,0.4773}};
    for (i=0; i<=3; i++)
    for (j=0; j<=3; j++)
      { br[i][j]=ar[i][j]; bi[i][j]=ai[i][j];}
    i=bcinv(ar,ai,4);
    if (i!=0)
      { printf("MAT AR IS:\n");
	for (i=0; i<=3; i++)
          { for (j=0; j<=3; j++)
              printf("%13.7e ",br[i][j]);
            printf("\n");
          }
        printf("\n");
        printf("MAT AI IS:\n");
        for (i=0; i<=3; i++)
          { for (j=0; j<=3; j++)
              printf("%13.7e ",bi[i][j]);
            printf("\n");
          }
        printf("\n");
        printf("MAT AR- IS:\n");
        for (i=0; i<=3; i++)
          { for (j=0; j<=3; j++)
              printf("%13.7e ",ar[i][j]);
            printf("\n");
          }
        printf("\n");
        printf("MAT AI- IS:\n");
        for (i=0; i<=3; i++)
          { for (j=0; j<=3; j++)
              printf("%13.7e ",ai[i][j]);
            printf("\n");
          }
        bcmul(br,bi,ar,ai,4,4,4,cr,ci);
        printf("\n");
        printf("MAT CR=AA- IS:\n");
        for (i=0; i<=3; i++)
          { for (j=0; j<=3; j++)
              printf("%13.7e ",cr[i][j]);
            printf("\n");
          }
        printf("\n");
        printf("MAT CI=AA- IS:\n");
        for (i=0; i<=3; i++)
          { for (j=0; j<=3; j++)
              printf("%13.7e ",ci[i][j]);
            printf("\n");
          }
      }
  }

