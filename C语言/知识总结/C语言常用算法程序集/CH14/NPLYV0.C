
  #include "stdio.h"
  #include "nplyv.c"
  main()
  { int i;
    static double a[7]={-20.0,7.0,-7.0,1.0,
                        3.0,-5.0,2.0};
    static double x[6]={0.9,-0.9,1.1,-1.1,1.3,-1.3};
    printf("\n");
    for (i=0; i<=5; i++)
      printf("x(%d)=%5.2lf   p(%d)=%13.7e\n",
             i,x[i],i,nplyv(a,7,x[i]));
    printf("\n");
  }

