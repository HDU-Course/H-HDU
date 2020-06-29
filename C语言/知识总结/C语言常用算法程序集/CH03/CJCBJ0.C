
  #include "stdio.h"
  #include "cjcbj.c"
  main()
  { int i,j;
    double eps;
    static double v[5][5];
    static double a[5][5]={ {10.0,1.0,2.0,3.0,4.0},
                            {1.0,9.0,-1.0,2.0,-3.0},
                            {2.0,-1.0,7.0,3.0,-5.0},
                            {3.0,2.0,3.0,12.0,-1.0},
                            {4.0,-3.0,-5.0,-1.0,15.0}};
    eps=0.000001;
    cjcbj(a,5,v,eps);
    for (i=0; i<=4; i++)
      printf("%13.7e\n",a[i][i]);
    printf("\n\n");
    for (i=0; i<=4; i++)
      { for (j=0; j<=4; j++)
          printf("%12.6e ",v[i][j]);
        printf("\n");
      }
    printf("\n");
  }

