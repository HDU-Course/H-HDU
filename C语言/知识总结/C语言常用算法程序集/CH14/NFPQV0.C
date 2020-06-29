
  #include "stdio.h"
  #include "nfpqv.c"
  main()
  { static double x[7]={1.0,2.0,3.0,4.0,5.0,6.0,0.0};
    static double b[7]={1.0,3.0,-1.0,2.0,
                            5.0,-8.0,11.0};
    double t;
    printf("\n");
    t=0.0;
    printf(" t=%3.1lf  y=%13.7e\n",t,nfpqv(x,b,7,t));
    printf("\n");
    t=3.5;
    printf(" t=%3.1lf  y=%13.7e\n",t,nfpqv(x,b,7,t));
    printf("\n");
  }

