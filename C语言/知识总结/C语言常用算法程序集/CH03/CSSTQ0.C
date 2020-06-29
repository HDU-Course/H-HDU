
  #include "stdio.h"
  #include "csstq.c"
  #include "cstrq.c"
  main()
  { int i,j,k,l=60;
    static double q[5][5],b[5],c[5];
    static double a[5][5]={ {10.0,1.0,2.0,3.0,4.0},
       {1.0,9.0,-1.0,2.0,-3.0},{2.0,-1.0,7.0,3.0,-5.0},
       {3.0,2.0,3.0,12.0,-1.0},{4.0,-3.0,-5.0,-1.0,15.0}};
    double eps=0.000001;
    cstrq(a,5,q,b,c);
    k=csstq(5,b,c,q,eps,l);
    printf("MAT A IS:\n");
    for (i=0; i<=4; i++)
      { for (j=0; j<=4; j++)
          printf("%13.7e ",a[i][j]);
        printf("\n");
      }
    printf("\n");
    if (k>0)
      { printf("MAT B IS:\n");
        for (i=0; i<=4; i++)
          printf("%13.7e ",b[i]);
        printf("\n\n");
        printf("MAT Q IS:\n");
        for (i=0; i<=4; i++)
          { for (j=0; j<=4; j++)
              printf("%13.7e ",q[i][j]);
            printf("\n");
          }
        printf("\n");
      }
  }

