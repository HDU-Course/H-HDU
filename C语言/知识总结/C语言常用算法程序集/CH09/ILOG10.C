
  #include "stdio.h"
  #include "ilog1.c"
  main()
  { int n;
    double t,a[7];
    static double x[12]={0.96,0.94,0.92,0.90,0.88,
               0.86,0.84,0.82,0.80,0.78,0.76,0.74};
    static double y[12]={558.0,313.0,174.0,97.0,55.8,
                  31.3,17.4,9.70,5.58,3.13,1.74,1.00};
    t=10.0; n=12;
    ilog1(n,x,y,t,a);
    printf("\n");
    printf("a=%13.7e   b=%13.7e  \n",a[1],a[0]);
    printf("\n");
    printf("q=%13.7e   s=%13.7e  \n",a[2],a[3]);
    printf("\n");
    printf("umax=%13.7e  umin=%13.7e  u=%13.7e \n",
                           a[4],a[5],a[6]);
    printf("\n");
  }

