
  #include "stdio.h"
  #include "btrch.c"
  main()
  { int n,i,j,k;
    static double t[6]={10.0,5.0,4.0,3.0,2.0,1.0};
    static double tt[6]={0.0,-1.0,-2.0,-3.0,-4.0,-5.0};
    static double b[6][6],a[6][6];
    n=6;
    i=btrch(t,tt,n,b);
    if (i>0)
      { printf("B=inv(T):\n");
        for (i=0; i<=5; i++)
          { for (j=0; j<=5; j++)
              printf("%12.6e ",b[i][j]);
            printf("\n");
          }
        printf("\n");
        printf("A=T*B:\n");
        for (i=1; i<=6; i++)
        for (j=1; j<=6; j++)
          { a[i-1][j-1]=0.0;
            for (k=1; k<=j-1; k++)
              a[i-1][j-1]=a[i-1][j-1]+b[i-1][k-1]*t[j-k];
            a[i-1][j-1]=a[i-1][j-1]+b[i-1][j-1]*t[0];
            for (k=j+1; k<=6; k++)
              a[i-1][j-1]=a[i-1][j-1]+b[i-1][k-1]*tt[k-j];
          }
        for (i=0; i<=5; i++)
          { for (j=0; j<=5; j++)
              printf("%12.6e ",a[i][j]);
            printf("\n");
          }
      }
  }

