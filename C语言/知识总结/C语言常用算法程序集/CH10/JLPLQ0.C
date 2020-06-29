
  #include "stdio.h"
  #include "jlplq.c"
  #include "brinv.c"
  #include "brmul.c"
  main()
  { int i;
    double x[6];
    static double a[3][6]={ {1.0,2.0,7.0,1.0,0.0,0.0},
     {1.0,4.0,13.0,0.0,1.0,0.0},{0.0,2.0,8.0,0.0,0.0,1.0}};
    static double b[3]={10.0,18.0,13.0};
    static double c[6]={-4.0,-9.0,-26.0,0.0,0.0,0.0};
    i=jlplq(a,b,c,3,3,x);
    printf("\n");
    if (i!=0)
      { for (i=0; i<=5; i++)
          printf("x(%2d)=%e\n",i,x[i]);
        printf("\n");
      }
  }

